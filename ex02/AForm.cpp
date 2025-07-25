#include "AForm.hpp"

AForm::AForm() : name_("Default"), sign_(100), exec_(100), isSigned_(false) {
    std::cout << "Default constructor for " << name_ << " form has been called\n";
}

AForm::AForm(const std::string& name, int sign, int exec) : name_(name), sign_(sign), exec_(exec) {
    isSigned_ = false;
    std::cout << "Constructor for " << name << " form has been called. Sign is " << sign << ", exec is " << exec << std::endl;
}

AForm::AForm(const AForm &other) : name_(other.name_), sign_(other.sign_), exec_(other.exec_), isSigned_(other.isSigned_) {
    std::cout << "Copy constructor for " << name_ << " form has been called.\n";
}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        this->sign_ = other.sign_;
        this->exec_ = other.exec_;
        this->isSigned_ = other.isSigned_;
    }
    return *this;
}

const std::string& AForm::getName() const {
    return name_;
}

int AForm::getSign() const {
    return sign_;
}

int AForm::getExec() const {
    return exec_;
}

bool AForm::getIsSigned() const {
    return isSigned_;
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low to sign the form!";
}

const char* AForm::NotSignedException::what() const throw() {
    return "The form is not signed!";
}

void AForm::beSigned(Bureaucrat const& b) {
    if (b.getGrade() > sign_)
        throw GradeTooLowException();
    isSigned_ = true;
}

void AForm::execute(Bureaucrat const & executor) const {
    if (!isSigned_)
        throw NotSignedException();
    if (executor.getGrade() > exec_)
        throw GradeTooLowException();

    executeAction();
}

AForm::~AForm() {
    std::cout << "Destructor has been called\n";
}
