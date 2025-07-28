#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat {
public:
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    const std::string& getName();
    int getGrade();

    void incrementGrade();
    void decrementGrade();

    class GradeTooHigh : public std::exception {
        public:
            const char* what() const throw();
    };

    class GradeTooLow : public std::exception {
        public:
            const char* what() const throw();
    };

private:
    const std::string name_;
    int grade_;
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& b);

#endif