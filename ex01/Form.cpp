#include "Form.hpp"
#include "Bureaucrat.hpp" 

Form::Form() : name_("Default"), isSigned_(false), signGrade_(100), executeGrade_(100) {
    std::cout << "Form " << name_ << " has been created\n";
}

Form::Form(const std::string& name, const int signGrade, const int executeGrade) : name_(name), signGrade_(signGrade), executeGrade_(executeGrade) {
    this->isSigned_ = false;
    if (signGrade < 1 || executeGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || executeGrade > 150)
        throw GradeTooLowException();
    std::cout << "Form " << name_ << " with signGrade " << signGrade_ << ", executeGrade " << executeGrade_ << " has been created\n";
}

Form::Form(Form &other) : name_(other.name_), isSigned_(other.isSigned_), signGrade_(other.signGrade_), executeGrade_(other.executeGrade_) {
    std::cout << "Copy constructor is used. Form " << name_ << " has been created\n";
}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        this->isSigned_ = other.isSigned_;
    }
    return *this;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

const std::string& Form::getName() const {
    return name_;
}

bool Form::getIsSigned() const {
    return isSigned_;
}

int Form::getSignGrade() const {
    return signGrade_;
}

int Form::getExecuteGrade() const {
    return executeGrade_;
}

void Form::beSigned(Bureaucrat& b) {
    if (b.getGrade() > signGrade_)
        throw GradeTooLowException();
    isSigned_ = true;
}

Form::~Form() {
    std::cout << "Form Destructor has been called\n";
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << f.getName() << " form with sign grade " << f.getSignGrade() << " and execute grade " << f.getExecuteGrade() << ", isSigned: " << f.getIsSigned();
    return os;
}