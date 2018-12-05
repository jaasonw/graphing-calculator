#include "Operand.h"
#include "Operator.h"
#include "FunctionToken.h"
#include "Token.h"
#include "rpn_constants.h"
#include "stack_queue/queue.h"
#include "stack_queue/stack.h"
#include <cctype>
#include <string>

double eval(Queue<Token*> tokens, double variable = 0);

Queue<Token*> infix_to_postfix(Queue<Token*> infix);

int find_mismatched_parenthesis(std::string equation);