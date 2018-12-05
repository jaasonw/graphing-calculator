#pragma once
#include "Token.h"
#include "rpn_constants.h"
#include <iostream>

class Operand : public Token
{
  private:
    double number;
  public:
    Operand();
    Operand(double number);
    int TypeOf() const { return NUMBER; };
    std::ostream &print(std::ostream &out) const;
    double get_number() { return this->number; }
};