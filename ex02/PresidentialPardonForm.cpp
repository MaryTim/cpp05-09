#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm(), target_("Default target") {
    std::cout << "Default constructor for " << target_ << " has been called for presidential pardon form\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("Presidential Pardon", 25, 5), target_(target) {
    std::cout << "Constructor for " << target_ << " has been called for presidential pardon form with" << this->getSign() << " sign and " << this->getExec() << " exec\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), target_(other.target_) {
    std::cout << "Copy constructor for target " << target_ << " for presidential pardon form has been called\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        this->target_ = other.target_;
    }
    return *this;
}

void PresidentialPardonForm::executeAction() const {
    std::cout << target_ << " has been pardoned by Zaphod Beeblebrox.\n";
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "Presidential pardon form destructor has been called\n";
}