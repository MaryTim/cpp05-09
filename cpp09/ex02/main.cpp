#include "Pmerge.hpp"
#include <climits>

static bool isPositiveInt(const std::string &str, unsigned int &out) {
    if (str.empty())
        return false;
    size_t i = 0;
    if (str[i] == '+') {
        i++;
    } else if (str[i] == '-') {
        return false;
    }
    unsigned long result = 0;
    while (i < str.size()) {
        char c = str[i];
        if (c < '0' || c > '9')
            return false;
        unsigned int digit = static_cast<unsigned int>(c - '0');
        if (result > (UINT_MAX - digit) / 10)
            return false;
        result = result * 10 + digit;
        i++;
    }
    if (result == 0)
        return false;
    out = static_cast<unsigned int>(result);
    return true;
    
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error. CHeck your args!\n";
        return 1;
    }

    std::vector<unsigned int> input;
    for (int i = 1; i < argc; i++) {
        unsigned int element;
        if (!isPositiveInt(std::string(argv[i]), element)) {
            std::cerr << "Error! Invalid input parameter!\n";
            return 1;
        }
        input.push_back(element);
    }
}