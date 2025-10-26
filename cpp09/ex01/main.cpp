#include "RPN.hpp"
#include <iostream>
#include <stdexcept>
#include <cctype>

static bool isOnlyWhitespace(const std::string& s) {
    for (std::string::const_iterator it = s.begin(); it != s.end(); ++it) {
        if (!std::isspace(static_cast<unsigned char>(*it)))
            return false;
    }
    return true;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error! Check number of arguments!" << std::endl;
        return 1;
    }
    const std::string input = argv[1];
    if (input.empty() || isOnlyWhitespace(input)) {
        std::cerr << "Error: empty or whitespace-only input" << std::endl;
        return 1;
    }
    try {
        int result = RPN::handleInput(input);
        std::cout << result << std::endl;
        return 0;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Error: unknown error" << std::endl;
        return 1;
    }
}
