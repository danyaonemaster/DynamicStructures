#include "BracketValidator.h"

bool BracketValidator::validate(const std::string& expression, std::string& errorPosition) {
    Stack<char> stack;
    size_t errorIndex = 0;

    for (size_t i = 0; i < expression.length(); ++i) {
        char ch = expression[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            stack.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (stack.empty() ||
                (ch == ')' && stack.top() != '(') ||
                (ch == ']' && stack.top() != '[') ||
                (ch == '}' && stack.top() != '{')) {
                errorIndex = i;
                errorPosition = expression.substr(0, errorIndex + 1);
                return false;
            }
            stack.pop();
        }
        else if (ch == ';') {
            break;
        }
    }

    if (!stack.empty()) {
        errorIndex = expression.length();
        errorPosition = expression;
        return false;
    }

    return true;
}