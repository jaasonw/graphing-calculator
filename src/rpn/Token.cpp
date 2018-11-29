#include "rpn/Token.h"
#include <iostream>

std::ostream &operator<<(std::ostream &out, const Token &t) {
    return t.print(out);
}