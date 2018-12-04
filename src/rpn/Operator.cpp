#include "rpn/Operator.h"
#include <cassert>
#include <iostream>

Operator::Operator() : _symbol('+') {}
Operator::Operator(char _symbol) : _symbol(_symbol) {}

double Operator::operate(double a, double b) {
    switch (this->_symbol) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            assert("unsupported operation" == "");
    }
    return -1;
}
int Operator::precedence() const {
    switch (this->_symbol) {
        case '+':
            return ADDITION;
        case '-':
            return SUBTRACTION;
        case '*':
            return MULTIPLICATION;
        case '/':
            return DIVISION;
        default:
            return -1;
    }
}

char Operator::symbol() const {
    return _symbol;
}

std::ostream& Operator::print(std::ostream &out) const {
    out << _symbol;
    return out;
}