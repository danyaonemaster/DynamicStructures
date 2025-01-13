#ifndef BRACKET_VALIDATOR_H
#define BRACKET_VALIDATOR_H

#include <string>
#include "Stack.h"

class BracketValidator {
public:
    static bool validate(const std::string& expression, std::string& errorPosition);
};

#endif