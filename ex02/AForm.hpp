#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat;

class AForm {
    public:
        AForm();
        AForm(const std::string& name, int sign, int exec);
        AForm(AForm& other);
        AForm& operator=(const AForm &other);
        virtual ~AForm();
        virtual void execute(Bureaucrat& b) const = 0;

        const std::string& getName() const;
        int getSign() const;
        int getExec() const;
        bool getIsSigned() const;
    private:
        const std::string name_;
        int sign_;
        int exec_;
        bool isSigned_;
};

#endif