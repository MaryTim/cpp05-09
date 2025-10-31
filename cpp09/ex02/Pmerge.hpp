#ifndef PMERGE_HPP
# define PMERGE_HPP

#include <vector>
#include <deque>
#include <iostream>

class PmergeMe {
    public:
        static void sortVector(std::vector<unsigned int> &v);
        static void sortDeque(std::deque<unsigned int> &d);

    private:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe& operator=(const PmergeMe &other);
        ~PmergeMe();
};

#endif