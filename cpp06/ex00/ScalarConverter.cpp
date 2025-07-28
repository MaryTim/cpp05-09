#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cmath>
#include <limits>
#include <iomanip>

bool isChar(const std::string& str) {
    return (str.length() == 1) && !std::isdigit(str[0]);
}

bool isInt(const std::string& str) {
    char *end;
    std::strtol(str.c_str(), &end, 10);
    return *end == '\0';
}

bool isFloat(const std::string& str) {
    if (str == "+inff" || str == "-inff" || str == "nanf")
        return true;
    char *end;
    std::strtof(str.c_str(), &end);
    return (*end == 'f' && *(end + 1) == '\0');
}

bool isDouble(const std::string& str) {
    if (str == "+inf" || str == "-inf" || str == "nan")
        return true;
    char *end;
    std::strtod(str.c_str(), &end);
    return *end == '\0';
}

void ScalarConverter::convert(const std::string& str) {
    double value = 0.0;
    bool isFl = false;

    if (isChar(str)) {
        char c = str[0];
        value = static_cast<double>(c);
    } else if (isInt(str)) {
        value = static_cast<double>(std::atoi(str.c_str()));
    } else if (isFloat(str)) {
        value = static_cast<double>(std::strtof(str.c_str(), NULL));
        isFl = true;
    } else if (isDouble(str)) {
        value = std::strtod(str.c_str(), NULL);
    } else {
        std::cout << "Error: Unknown literal format." << std::endl;
        return ;
    }

    std::cout << "char: ";
    if (std::isnan(value) || value < 0 || value > 127 || !std::isprint(value)) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
    }

    std::cout << "int: ";
    if (std::isnan(value) || value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min()) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << static_cast<int>(value) << std::endl;
    }

    std::cout << "float: ";
    float f = static_cast<float>(value);
    std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;

    std::cout << "double: ";
    std::cout << std::fixed << std::setprecision(1) << value << std::endl;
}