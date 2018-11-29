#include "../include/Operand.h"
#include "../include/Operator.h"
#include "../include/Token.h"
#include "../include/constants.h"
#include "../include/stack_queue/queue.h"
#include "../include/stack_queue/stack.h"
#include <string>
#include <cctype>

double eval(Queue<Token*> tokens, double variable = 0);

Queue<Token*> infix_to_postfix(Queue<Token*> infix);