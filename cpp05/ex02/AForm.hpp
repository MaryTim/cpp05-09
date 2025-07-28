#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class AForm {
    public:
        AForm();
        AForm(const std::string& name, int sign, int exec);
        AForm(const AForm& other);
        AForm& operator=(const AForm &other);
        virtual ~AForm();

        void execute(Bureaucrat const & executor) const;  //validation for all forms
        virtual void executeAction() const = 0;

        const std::string& getName() const;
        int getSign() const;
        int getExec() const;
        bool getIsSigned() const;

        class NotSignedException : public std::exception {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };

        void beSigned(Bureaucrat const &);

    private:
        const std::string name_;
        int sign_;
        int exec_;
        bool isSigned_;
};

#endif