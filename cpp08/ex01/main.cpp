#include "Span.hpp"
#include <iostream>
#include <cstdlib>

int main() {
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl; // 2
        std::cout << sp.longestSpan() << std::endl;  // 14
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    try {
        Span big(10000);
        std::vector<int> values(10000);
        for (int i = 0; i < 10000; i++) {
            values[i] = rand();
        }
        big.addRange(values.begin(), values.end());
        std::cout << "Big span OK" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}