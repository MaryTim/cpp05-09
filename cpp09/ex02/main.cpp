#include "Pmerge.hpp"
#include <climits>


static bool isPositiveInt(const std::string &str, unsigned int &out) {
    if (str.empty())
        return false;
    size_t i = 0;
    if (str[i] == '+') {
        i++;
    } else if (str[i] == '-') {
        return false;
    }
    unsigned long result = 0;
    while (i < str.size()) {
        char c = str[i];
        if (c < '0' || c > '9')
            return false;
        unsigned int digit = static_cast<unsigned int>(c - '0');
        if (result > (UINT_MAX - digit) / 10)
            return false;
        result = result * 10 + digit;
        i++;
    }
    if (result == 0)
        return false;
    out = static_cast<unsigned int>(result);
    return true;
}

static void printOutContainer(const std::vector<unsigned int> &v) {
    for (std::size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << ' ';
    }
    std::cout << "\n";
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error. CHeck your args!\n";
        return 1;
    }

    // validate all passed arguments are positive
    std::vector<unsigned int> input;
    for (int i = 1; i < argc; i++) {
        unsigned int element;
        if (!isPositiveInt(std::string(argv[i]), element)) {
            std::cerr << "Error! Invalid input parameter!\n";
            return 1;
        }
        input.push_back(element);
    }

    std::vector<unsigned int> v = input;
    std::deque<unsigned int> d(input.begin(), input.end());

    std::cout << "Before: ";
    printOutContainer(input);

    timeval start;
    timeval end;

    PmergeMe::now(start);
    PmergeMe::sortVector(v);
    PmergeMe::now(end);
    double usVector = PmergeMe::timeDiff(start, end);

    PmergeMe::now(start);
    PmergeMe::sortDeque(d);
    PmergeMe::now(end);
    double usDeque = PmergeMe::timeDiff(start, end);

    std::cout << "After: ";
    printOutContainer(v);

    std::cout.setf(std::ios::fixed); //fix float number
    std::cout.precision(6);
    
    std::cout << "Time to process a range of " << input.size()
              << " elements with std::vector : " << usVector << " us\n";
    std::cout << "Time to process a range of " << input.size()
              << " elements with std::deque  : " << usDeque << " us\n";
    return 0;
}