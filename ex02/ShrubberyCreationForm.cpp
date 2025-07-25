#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), target_("Default target") {
    std::cout << "Default constructor for " << target_ << " has been called for Shrubbery creation form\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), target_(target) {
    std::cout << "Constructor for " << target_ << " has been called for shrubbery creation form with" << this->getSign() << " sign and " << this->getExec() << " exec\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target_(other.target_) {
    std::cout << "Copy constructor for target " << target_ << " for shrubbery creation form has been called\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        this->target_ = other.target_;
    }
    return *this;
}

void ShrubberyCreationForm::executeAction() const {
    std::ofstream outfile((target_ + "_shrubbery").c_str());
    if (!outfile) {
        std::cerr << "Error: could not create file\n";
        return;
    }

    outfile << "       _-_\n"
            << "    /~~   ~~\\\n"
            << " /~~         ~~\\\n"
            << "{               }\n"
            << " \\  _-     -_  /\n"
            << "   ~  \\\\ //  ~\n"
            << "_- -   | | _- _\n"
            << "  _ -  | |   -_\n"
            << "       | |\n";

    std::cout << "Shrubbery created at " << target_ + "_shrubbery" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "Shrubbery creation form destructor has been called\n";
}