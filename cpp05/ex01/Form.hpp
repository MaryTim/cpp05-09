#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat;

class Form {
public:
    Form();
    Form(const std::string& name, const int signGrade, const int executeGrade);
    Form(Form &other);
    Form& operator=(const Form& other);
    ~Form();

    class GradeTooHighException : public std::exception {
        public:
            const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        public:
            const char* what() const throw();
    };

    const std::string& getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;

    void beSigned(Bureaucrat& b);
private:
    const std::string name_;
    bool isSigned_;
    const int signGrade_;
    const int executeGrade_;
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif