#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>

int main() {
    Intern random;

    try {
        AForm* form1 = random.makeForm("robotomy request", "Bender");
        std::cout << "Form created: " << form1->getName() << " targeting " << form1->getTarget() << std::endl;
        delete form1;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "-----------------------------" << std::endl;
    try {
        AForm* form2 = random.makeForm("explosion protocol", "Bender");
        delete form2;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}


