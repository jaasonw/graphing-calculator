#include "Operand.h"
#include "Operator.h"
#include "Token.h"
#include "constants.h"
#include "stack_queue/queue.h"
#include "stack_queue/stack.h"
#include <string>
#include <cctype>

double eval(Queue<Token*> tokens, double variable = 0);

Queue<Token*> infix_to_postfix(Queue<Token*> infix);