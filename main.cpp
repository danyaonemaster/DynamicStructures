#include <iostream>
#include "BracketValidator.h"
using namespace std;

int main() {
    string expression;
    cout << "Enter the expression ending with ';': ";
    getline(cin, expression);

    string errorPosition;
    if (BracketValidator::validate(expression, errorPosition)) {
        cout << "The expression is correct." << std::endl;
    }
    else {
        cout << "The expression is incorrect. Error at: " << errorPosition << std::endl;
    }
}
