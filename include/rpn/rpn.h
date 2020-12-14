#include <cctype>
#include <memory>
#include <queue>
#include <stack>
#include <string>

#include "FunctionToken.h"
#include "Operand.h"
#include "Operator.h"
#include "Token.h"
#include "Variable.h"
#include "rpn_constants.h"

double eval(std::queue<std::shared_ptr<Token>> tokens, double variable = 0);

std::queue<std::shared_ptr<Token>> infix_to_postfix(
    std::queue<std::shared_ptr<Token>> infix);

int find_mismatched_parenthesis(std::string equation);

std::queue<std::shared_ptr<Token>> tokenize(std::string equation);