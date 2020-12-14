#include "rpn/rpn.h"

double eval(std::queue<std::shared_ptr<Token>> tokens, double variable) {
    std::stack<std::shared_ptr<Token>> call_stack =
        std::stack<std::shared_ptr<Token>>();
    while (!tokens.empty()) {
        std::shared_ptr<Token> current_token = tokens.front();
        tokens.pop();
        switch (current_token->TypeOf()) {
            case OPERATOR: {
                // auto base_token =
                std::shared_ptr<Operator> operator_token =
                    std::static_pointer_cast<Operator>(current_token);
                std::shared_ptr<Operand> right =
                    std::static_pointer_cast<Operand>(call_stack.top());
                call_stack.pop();
                std::shared_ptr<Operand> left =
                    std::static_pointer_cast<Operand>(call_stack.top());
                call_stack.pop();
                call_stack.push(std::shared_ptr<Operand>(
                    new Operand(operator_token->operate(left->get_number(),
                                                        right->get_number()))));
                break;
            }
            case NUMBER:
                call_stack.push(current_token);
                break;
            case VARIABLE:
                // push in operand to take the place of the variable
                call_stack.push(
                    std::shared_ptr<Operand>(new Operand(variable)));
                break;
            case FUNCTION:
                std::shared_ptr<FunctionToken> function_token =
                    std::static_pointer_cast<FunctionToken>(current_token);
                std::shared_ptr<Operand> num =
                    std::static_pointer_cast<Operand>(call_stack.top());
                call_stack.pop();
                call_stack.push(std::shared_ptr<Operand>(
                    new Operand(function_token->operate(num->get_number()))));
                break;
        }
    }
    std::shared_ptr<Token> result = call_stack.top();
    call_stack.pop();
    double result_number =
        std::static_pointer_cast<Operand>(result)->get_number();

    // clean up the rest of the queue & stack if for some reason they're not
    // empty while (!tokens.empty()) {
    //     // delete tokens.pop();
    // }
    // while (!call_stack.empty()) {
    //     // delete call_stack.pop();
    // }
    return result_number;
}

std::queue<std::shared_ptr<Token>> infix_to_postfix(
    std::queue<std::shared_ptr<Token>> infix) {
    std::queue<std::shared_ptr<Token>> output_queue;
    std::stack<std::shared_ptr<Token>> operator_stack;
    while (!infix.empty()) {
        std::shared_ptr<Token> token = infix.front();
        infix.pop();
        switch (token->TypeOf()) {
            case NUMBER:
                output_queue.push(token);
                break;
            case VARIABLE:
                output_queue.push(token);
                break;
            case FUNCTION:
                operator_stack.push(token);
                break;
            case OPERATOR:
                std::shared_ptr<Operator> op =
                    std::static_pointer_cast<Operator>(token);
                if (op->precedence() == -1)
                    operator_stack.push(op);
                else if (!operator_stack.empty()) {
                    std::shared_ptr<Token> top =
                        std::shared_ptr<Token>(operator_stack.top());
                    while (
                        !operator_stack.empty() && top->TypeOf() == OPERATOR &&
                        std::static_pointer_cast<Operator>(top)->precedence() >
                            op->precedence()) {
                        // ignore parenthesis
                        if (std::static_pointer_cast<Operator>(top)
                                ->precedence() == -1)
                            break;
                        output_queue.push(operator_stack.top());
                        operator_stack.pop();
                        if (!operator_stack.empty())
                            top = std::shared_ptr<Token>(operator_stack.top());
                    }
                    operator_stack.push(op);
                } else {
                    operator_stack.push(op);
                }

                if (op->symbol() == ')') {
                    operator_stack.pop();
                    std::shared_ptr<Token> top =
                        std::shared_ptr<Token>(operator_stack.top());
                    while (!operator_stack.empty() &&
                           top->TypeOf() == OPERATOR &&
                           std::static_pointer_cast<Operator>(top)->symbol() !=
                               '(') {
                        output_queue.push(operator_stack.top());
                        operator_stack.pop();
                        top = std::shared_ptr<Token>(operator_stack.top());
                    }
                    operator_stack.pop();
                    top = std::shared_ptr<Token>(operator_stack.top());
                    if (top->TypeOf() == FUNCTION) {
                        output_queue.push(operator_stack.top());
                        operator_stack.pop();
                    }
                }
                break;
        }
    }
    while (!operator_stack.empty()) {
        auto op = std::static_pointer_cast<Operator>(operator_stack.top());
        operator_stack.pop();
        if (op->symbol() != '(' && op->symbol() != ')') output_queue.push(op);
    }
    return output_queue;
}

// takes an equation string and counts the number of mismatched parenthesis
// returns a negative for number of left parenthesis missing
// returns a positive for number of right parenthesis missing
int find_mismatched_parenthesis(std::string equation) {
    int left = 0;
    int right = 0;
    for (int i = 0; i < equation.size(); i++) {
        if (equation.at(i) == '(') {
            left++;
        }
        if (equation.at(i) == ')') {
            right++;
        }
    }
    return left - right;
}

// takes an infix expression and tokenizes it into a queue
// supports turning 2x into 2 * x
// does not assume input checking
std::queue<std::shared_ptr<Token>> tokenize(std::string equation) {
    if (find_mismatched_parenthesis(equation) != 0)
        throw "mismatched parenthesis";
    std::queue<std::shared_ptr<Token>> tokenized;

    // load equation into queue, skip whitespace
    std::queue<char> token_chars;
    for (int i = 0; i < equation.size(); i++) {
        if (equation.at(i) != ' ') token_chars.push(equation.at(i));
    }

    std::shared_ptr<Token> last_token = NULL;
    bool unary = false;
    while (!token_chars.empty()) {
        // get 1st character
        std::string token = "";
        token += token_chars.front();
        token_chars.pop();

        // tokenize digits;
        if (isdigit(token.at(0))) {
            // check if the top of the queue is a . or a number
            while (!token_chars.empty() && (isdigit(token_chars.front()) ||
                                            token_chars.front() == '.')) {
                token += token_chars.front();
                token_chars.pop();
            }
            std::shared_ptr<Token> operand(new Operand(atof(token.c_str())));
            tokenized.push(operand);
            last_token = operand;
        }
        // tokenize something that can either be a function or a variable
        else if (isalpha(token.at(0))) {
            // this was probably a case like 5x, add a multiplication token
            if (last_token != NULL && last_token->TypeOf() == NUMBER) {
                last_token = std::shared_ptr<Token>(new Operator('*'));
                tokenized.push(last_token);
            }
            std::shared_ptr<Token> function_or_variable = nullptr;
            // decide if we're working with a variable or a function here
            if (token_chars.empty() || !isalpha(token_chars.front())) {
                // it's variable
                function_or_variable =
                    std::shared_ptr<Variable>(new Variable(token.at(0)));
            }
            // it's a function
            else {
                while (!token_chars.empty() && isalpha(token_chars.front())) {
                    token += token_chars.front();
                    token_chars.pop();
                }
                function_or_variable =
                    std::shared_ptr<FunctionToken>(new FunctionToken(token));
            }
            tokenized.push(function_or_variable);
            last_token = function_or_variable;
        }
        // if it's not a letter or a number it's probably a symbol
        else {
            // unary operator, insert a -1 * ()
            if ((last_token == NULL || last_token->TypeOf() != NUMBER) &&
                token.at(0) == '-') {
                tokenized.push(std::shared_ptr<Operand>(new Operand(-1)));
                tokenized.push(std::shared_ptr<Operator>(new Operator('*')));
                last_token = std::shared_ptr<Operator>(new Operator('('));
                unary = true;
            } else {
                last_token =
                    std::shared_ptr<Operator>(new Operator(token.at(0)));
            }
            tokenized.push(last_token);
        }
        if (unary) {
            last_token = std::shared_ptr<Operator>(new Operator(')'));
            tokenized.push(last_token);
            unary = false;
        }
    }
    return tokenized;
}
