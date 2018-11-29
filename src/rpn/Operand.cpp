#include "rpn/Operand.h"
#include <iostream>

Operand::Operand() : number(0) {}
Operand::Operand(double number) : number(number) {}

std::ostream& Operand::print(std::ostream &out) const {
    out << number;
    return out;
}