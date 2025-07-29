#include "Array.hpp"
#include <iostream>

int main() {
    try {
        // default constructor
        Array<int> a; 
        std::cout << "a.size(): " << a.size() << std::endl;

        // constructor with size
        Array<int> b(5);
        for (unsigned int i = 0; i < b.size(); i++)
            b[i] = i + 1;

        std::cout << "b contents: ";
        for (unsigned int i = 0; i < b.size(); ++i)
            std::cout << b[i] << std::endl;

        // Copy constructor
        Array<int> c = b;
        c[0] = 999;

        std::cout << "After modifying c[0] b[0]: " << b[0] << ", c[0]: " << c[0] << std::endl;

        // Assignment operator
        Array<int> d;
        d = b;
        d[1] = 777;

        std::cout << "After modifying d[1] b[1]: " << b[1] << ", d[1]: " << d[1] << std::endl;

        // Bounds check
        std::cout << "Accessing out-of-bounds index:" << std::endl;
        std::cout << b[10] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}