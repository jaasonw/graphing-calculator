#pragma once
#include "Token.h"
#include "rpn_constants.h"
#include <iostream>

class Variable : public Token {
private:
    char symbol;

public:
    Variable();
    Variable(char symbol);
    int TypeOf() const { return VARIABLE; };
    std::ostream& print(std::ostream& out) const;
};