#ifndef PMERGE_HPP
# define PMERGE_HPP

#include <vector>
#include <deque>
#include <iostream>

class PmergeMe {
    public:
        static void sortVector(std::vector<unsigned int> &v);
        static void sortDeque(std::deque<unsigned int> &d);

        static void now(struct timeval &tv);
        static double elapsedUS(const struct timeval &a, const struct timeval &b);
    private:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe& operator=(const PmergeMe &other);
        ~PmergeMe();
};

#endif