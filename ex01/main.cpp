#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat b("Bob", 100);
        Form f("C98", 50, 50);
        b.signForm(f);
    } catch (std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat a("Angela", 12);
        Form f("C98", 40, 40);
        a.signForm(f);
    } catch (std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}