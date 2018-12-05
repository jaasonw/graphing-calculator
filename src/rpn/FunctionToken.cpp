#include "rpn/FunctionToken.h"
#include <cassert>
#include <iostream>

FunctionToken::FunctionToken() : function("") {}
FunctionToken::FunctionToken(std::string function) : function(function) {}

double FunctionToken::operate(double x) {
    // too lazy to copy pasta everything gl
    if (function == "sin")
        return sin(x);
    else if (function == "cos")
        return cos(x);
    else if (function == "tan")
        return tan(x);
    else if (function == "asin")
        return asin(x);
    else if (function == "acos")
        return acos(x);
    else if (function == "atan")
        return atan(x);
    else if (function == "abs")
        return abs(x);
    else if (function == "sqrt")
        return sqrt(x);
    else
        return x;
}


std::string FunctionToken::function_name() const { return function; }

std::ostream& FunctionToken::print(std::ostream& out) const {
    out << function;
    return out;
}