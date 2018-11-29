#include "../include/Variable.h"
#include <cassert>
#include <iostream>

Variable::Variable() : symbol('x') {}
Variable::Variable(char symbol) : symbol(symbol) {}

std::ostream& Variable::print(std::ostream &out) const {
    out << symbol;
    return out;
}