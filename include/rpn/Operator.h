#pragma once
#include "Token.h"
#include "rpn_constants.h"
#include <cmath>
#include <iostream>

class Operator : public Token {
private:
    char _symbol;

public:
    Operator();
    Operator(char _symbol);
    int TypeOf() const { return OPERATOR; };
    int precedence() const;
    char symbol() const;
    std::ostream &print(std::ostream &out) const;
    double operate(double a, double b);
};