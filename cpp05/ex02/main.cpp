#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat alice("Alice", 1);
        Bureaucrat bob("Bob", 140);

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Rob");
        PresidentialPardonForm pardon("Joanna");

        std::cout << "\n=== Attempting to sign forms ===" << std::endl;
        bob.signForm(shrub); // should succeed (145 >= 140)
        bob.signForm(robot); // should fail
        alice.signForm(robot); // should succeed
        alice.signForm(pardon); // should succeed

        std::cout << "\n=== Attempting to execute forms ===" << std::endl;
        bob.executeForm(shrub); // should fail, Bob 140, form 137
        bob.executeForm(robot); // should fail bob 140, form 45
        alice.executeForm(robot); // should succeed
        alice.executeForm(pardon); // should succeed

    } catch (const std::exception& e) {
        std::cerr << "Unhandled exception: " << e.what() << std::endl;
    }
    return 0;
}


