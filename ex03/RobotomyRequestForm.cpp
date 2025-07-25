#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm(), target_("Default target") {
    std::cout << "Default constructor for " << target_ << " has been called for robotomy request form\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), target_(target) {
    std::cout << "Constructor for " << target_ << " has been called for robotomy request form with" << this->getSign() << " sign and " << this->getExec() << " exec\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target_(other.target_) {
    std::cout << "Copy constructor for target " << target_ << " for robotomy request form has been called\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        this->target_ = other.target_;
    }
    return *this;
}

void RobotomyRequestForm::executeAction() const {
    std::cout << "Bzzz... Drrrrr..." << std::endl;
    if (std::rand() % 2)
        std::cout << target_ << " has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomy of " << target_ << " failed." << std::endl;
}

const std::string& RobotomyRequestForm::getTarget() const {
    return target_;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "Robotomy request form destructor has been called\n";
}