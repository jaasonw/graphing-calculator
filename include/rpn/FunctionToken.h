#pragma once
#include <cmath>
#include <iostream>
#include <string>

#include "Token.h"
#include "rpn_constants.h"

class FunctionToken : public Token {
   private:
    std::string function;

   public:
    FunctionToken();
    FunctionToken(std::string function);
    int TypeOf() const { return FUNCTION; };
    std::string function_name() const;
    std::ostream& print(std::ostream& out) const;
    double operate(double x);
};