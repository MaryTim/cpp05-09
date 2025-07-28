#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("Default"), grade_(1) {
    std::cout << name_ << " bureaucrat was created\n";
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name_(name), grade_(grade) {
    if (grade < 1)
        throw GradeTooHigh();
    if (grade > 150)
        throw GradeTooLow();
    std::cout << "Bureaucrat " << name_  << " with grade " << grade_ << " was created\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name_(other.name_), grade_(other.grade_) {
    std::cout << "Copy constructor is used. Bureaucrat " << name_ << " was created. Grade: " << grade_ << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        this->grade_ = other.grade_;
    }
    return *this;
}

const std::string& Bureaucrat::getName() {
    return name_;
}

int Bureaucrat::getGrade() {
    return grade_;
}

void Bureaucrat::incrementGrade() {
    if (grade_ <= 1)
        throw GradeTooHigh();
    grade_ --;
    std::cout << "The grade is " << grade_ << std::endl;
}

void Bureaucrat::decrementGrade() {
    if (grade_ >= 150)
        throw GradeTooLow();
    grade_ ++;
    std::cout << "The grade is " << grade_ << std::endl;
}

const char* Bureaucrat::GradeTooHigh::what() const throw() {
    return "Grade too high!";
}

const char* Bureaucrat::GradeTooLow::what() const throw() {
    return "Grade too low!";
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Destructor has been called\n";
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}