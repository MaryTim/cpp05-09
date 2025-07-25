#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {
    std::cout << "Default constructor for intern has been called\n";
}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {
    std::cout << "Destructor for intern has been called\n";
}

const char* Intern::FormDoesntExistException::what() const throw() {
    return "Intern: the requested form type doesn't exist\n";
}

AForm* Intern::makeForm(const std::string& formName, const std::string& formTarget) const {
    std::string formTypes[3] = { "shrubbery creation", "robotomy request", "presidential pardon" };
    int formIndex = -1;
    for (int i = 0; i < 3; i++) {
        if (formName == formTypes[i]) {
            formIndex = i;
            break;
        }
    }

    switch(formIndex) {
        case 0:
            std::cout << "Intern creates shrubbery creation" << std::endl;
            return new ShrubberyCreationForm(formTarget);
        case 1:
            std::cout << "Intern creates robotomy request" << std::endl;
            return new RobotomyRequestForm(formTarget);
        case 2:
            std::cout << "Intern creates presidential pardon"<< std::endl;
            return new PresidentialPardonForm(formTarget);
        default:
            std::cerr << "Intern cannot create form: '" << formName << "This form is unknown." << std::endl;
            throw FormDoesntExistException();
    }
}