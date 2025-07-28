#include <ctime>
#include <iostream>
#include <cstdlib> 
#include "Base.hpp"

Base* generate();
void identify(Base* p);
void identify(Base& p);

int main() {
    std::srand(std::time(NULL));

    Base *object = generate();

    std::cout << "identify(Base*): ";
    identify(object);

    std::cout << "identify(Base&): ";
    identify(*object);

    delete object;

    return 0;
}