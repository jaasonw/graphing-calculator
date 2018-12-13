#include "rpn/rpn.h"

double eval(Queue<Token*> tokens, double variable) {
    Stack<Token*> call_stack = Stack<Token*>();
    while (!tokens.empty()) {
        Token* current_token = tokens.pop();
        switch(current_token->TypeOf()) {
            case OPERATOR: {
                Operator* operator_token = static_cast<Operator*>(current_token);
                Operand* right = static_cast<Operand*>(call_stack.pop());
                Operand* left = static_cast<Operand*>(call_stack.pop());
                call_stack.push(new Operand(operator_token->operate(left->get_number(), right->get_number())));
                // delete left;
                // delete right;
                // delete current_token;
                break;
            }
            case NUMBER:
                call_stack.push(current_token);
                break;
            case VARIABLE:
                // push in operand to take the place of the variable
                call_stack.push(new Operand(variable));
                // make sure to delete the variable token
                // delete current_token;
                break;
            case FUNCTION:
                FunctionToken* function_token = static_cast<FunctionToken*>(current_token);
                Operand* num = static_cast<Operand*>(call_stack.pop());
                call_stack.push(new Operand(function_token->operate(num->get_number())));
                // delete num;
                break;
        }
    }
    Token* result = call_stack.pop();
    double result_number = static_cast<Operand*>(result)->get_number();
    delete result;

    // clean up the rest of the queue & stack if for some reason they're not
    // empty
    while (!tokens.empty()) {
        // delete tokens.pop();
    }
    while (!call_stack.empty()) {
        // delete call_stack.pop();
    }
    return result_number;
}

Queue<Token*> infix_to_postfix(Queue<Token*> infix) {
    Queue<Token*> output_queue;
    Stack<Token*> operator_stack;
    while (!infix.empty()) {
        Token* token = infix.pop();
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
                Operator* op = static_cast<Operator*>(token);
                if (op->precedence() == -1)
                    operator_stack.push(op);
                else if (!operator_stack.empty()) {
                    Token* top = *(operator_stack.begin());
                    while (!operator_stack.empty() && top->TypeOf() == OPERATOR && static_cast<Operator*>(top)->precedence() > op->precedence()) {
                        // ignore parenthesis
                        if (static_cast<Operator*>(top)->precedence() == -1)
                            break;
                        output_queue.push(operator_stack.pop());
                        if (!operator_stack.empty())
                            top = *(operator_stack.begin());
                    }
                    operator_stack.push(op);
                }
                else {
                    operator_stack.push(op);
                }

                if (op->symbol() == ')') {
                    delete operator_stack.pop();
                    Token* top = *(operator_stack.begin());
                    while (!operator_stack.empty() && top->TypeOf() == OPERATOR && static_cast<Operator*>(top)->symbol() != '(') {
                        output_queue.push(operator_stack.pop());
                        top = *(operator_stack.begin());
                    }
                    delete operator_stack.pop();
                    top = *(operator_stack.begin());
                    if (top->TypeOf() == FUNCTION)
                        output_queue.push(operator_stack.pop());
                }
                break;
        }
    }
    while (!operator_stack.empty()) {
        auto op = static_cast<Operator*>(operator_stack.pop());
        if (op->symbol() != '(' && op->symbol() != ')')
            output_queue.push(op);
        else
            delete op;
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
Queue<Token*> tokenize(std::string equation) {

    if (find_mismatched_parenthesis(equation) != 0)
        throw "mismatched parenthesis";
    Queue<Token*> tokenized;

    // load equation into queue, skip whitespace
    Queue<char> token_chars;
    for (int i = 0; i < equation.size(); i++) {

        if (equation.at(i) != ' ')
            token_chars.push(equation.at(i));
    }

    Token* last_token = NULL;
    while (!token_chars.empty()) {
        // get 1st character
        std::string token = "";
        token += token_chars.pop();

        // tokenize digits;
        if (isdigit(token.at(0))) {
            // check if the top of the queue is a . or a number
            while (!token_chars.empty() && (isdigit(*token_chars.begin()) ||
                                            *token_chars.begin() == '.')) {
                token += token_chars.pop();
            }
            Token* operand = new Operand(atof(token.c_str()));
            tokenized.push(operand);
            last_token = operand;
        }
        // tokenize something that can either be a function or a variable
        else if (isalpha(token.at(0))) {
            // this was probably a case like 5x, add a multiplication token
            if (last_token != NULL && last_token->TypeOf() == NUMBER) {
                last_token = new Operator('*');
                tokenized.push(last_token);
            }
            Token* function_or_variable = NULL;
            // decide if we're working with a variable or a function here
            if (token_chars.empty() || !isalpha(*token_chars.begin())) {
                // it's variable
                function_or_variable = new Variable(token.at(0));
            }
            // it's a function
            else {
                while (!token_chars.empty() && isalpha(*token_chars.begin())) {
                    token += token_chars.pop();
                }
                function_or_variable = new FunctionToken(token);
            }
            tokenized.push(function_or_variable);
            last_token = function_or_variable;
        }
        // if it's not a letter or a number it's probably a symbol
        else {
            last_token = new Operator(token.at(0));
            tokenized.push(last_token);
        }
    }
    return tokenized;
}
