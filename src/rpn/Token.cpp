#include "rpn/Token.h"
#include <iostream>

int Token::TypeOf() const { return GENERIC; }

std::ostream &operator<<(std::ostream &out, const Token &t) {
    return t.print(out);
}