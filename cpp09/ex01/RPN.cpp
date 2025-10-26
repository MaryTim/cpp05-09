#include "RPN.hpp"
#include <stack>
#include <sstream>
#include <stdexcept>
#include <cctype>

RPN::RPN() {}

bool RPN::isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int RPN::useOperator(int a, int b, char o) {
    switch (o) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0) {
                throw std::runtime_error("division by 0");
            }
            return a / b;
        default:
            throw std::runtime_error("invalid operator");
    }
}

int RPN::handleInput(const std::string &s) {
    std::stack<int> myStack;

    for (std::size_t i = 0; i < s.size(); i++) {
        unsigned char element = static_cast<unsigned char>(s[i]);

        if (std::isspace(element)) 
            continue;
        if (std::isdigit(element)) {
            myStack.push(element - '0');
            continue;
        }
        if (isOperator(static_cast<char>(element))) {
            if (myStack.size() < 2) {
                throw std::runtime_error("not enough values to work with");
            }
            int b = myStack.top();
            myStack.pop();
            int a = myStack.top();
            myStack.pop();
            myStack.push(useOperator(a, b, static_cast<char>(element)));
            continue;
        }
        throw std::runtime_error("invalid character");
    }
    if (myStack.size() != 1) {
        throw std::runtime_error("some digits are left unused!");
    }
    return myStack.top();
}
