#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b("Bob", 0);
    } catch (std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    try {
        Bureaucrat a("Dean", 2);
        a.incrementGrade();
        a.incrementGrade();
    } catch (std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
        try {
        Bureaucrat c("Angela", 149);
        c.decrementGrade();
        c.decrementGrade();
    } catch (std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}