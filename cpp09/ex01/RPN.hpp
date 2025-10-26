#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>

class RPN {
    public:
        static int handleInput(const std::string &s);
    private:
        RPN();
        RPN(const RPN&);
        RPN& operator=(const RPN&);
        ~RPN();
        static bool isOperator(char c);
        static int useOperator(int a, int b, char o);
};

#endif