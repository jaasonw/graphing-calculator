#pragma once
#include "rpn_constants.h"
#include <iostream>
#include "rpn_constants.h"

class Token {
private:
public:
    friend std::ostream& operator<<(std::ostream& out, const Token& t);
    virtual std::ostream& print(std::ostream& out) const;
    virtual int TypeOf() const;
};