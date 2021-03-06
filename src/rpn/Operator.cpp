#include "rpn/Operator.h"
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
        case '^':
            return pow(a, b);
        default:
            throw "unsupported operation: " + this->_symbol;
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
        case '^':
            return EXPONENT;
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