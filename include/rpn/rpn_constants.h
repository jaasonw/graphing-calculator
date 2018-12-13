#pragma once
// types
const int GENERIC = -1;
const int NUMBER = 0;
const int OPERATOR = 1;
const int VARIABLE = 2;
const int FUNCTION = 3;

// precedence
const int SUBTRACTION = 0;
const int ADDITION = 0;
const int DIVISION = 1;
const int MULTIPLICATION = 1;
const int EXPONENT = 2;

// association
const int LEFT = 0;
const int RIGHT = 1;