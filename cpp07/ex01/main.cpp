#include <iostream>
#include "Iter.hpp"

template <typename T>
void print(T& value) {
    std::cout << value << std::endl;
}

void increment(int& x) {
    x++;
}

int main() {
    int intArr[] = {1, 2, 3, 4, 5};
    std::size_t intSize = sizeof(intArr) / sizeof(intArr[0]);

    std::cout << "Original int array:" << std::endl;
    iter(intArr, intSize, print<int>);

    std::cout << "After incrementing:" << std::endl;
    iter(intArr, intSize, increment);
    iter(intArr, intSize, print<int>);

    std::string strArr[] = {"hello", "world", "template"};
    std::size_t strSize = sizeof(strArr) / sizeof(strArr[0]);

    std::cout << "String array:" << std::endl;
    iter(strArr, strSize, print<std::string>);

    return 0;
}