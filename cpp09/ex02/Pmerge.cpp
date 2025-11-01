#include "Pmerge.hpp"

//time
void PmergeMe::now(struct timeval &tv) {
    gettimeofday(&tv, NULL);
}

double PmergeMe::timeDiff(const struct timeval &a, const struct timeval &b) {
    long sec = b.tv_sec - a.tv_sec;
    long usec = b.tv_usec - a.tv_usec;
    return static_cast<double>(sec) * 1e6 + static_cast<double>(usec);
}

//sort containers
void PmergeMe::sortVector(std::vector<unsigned int> &v) {
    v_mergeInsert(v);
}

void PmergeMe::sortDeque(std::deque<unsigned int>& d) {
    d_mergeInsert(d);
}

// vector

// 1. make pairs from initial vector
void PmergeMe::v_getPairs(const std::vector<unsigned int> &input, 
                                std::vector<VectorPair> &pairs, 
                                bool &hasTail, 
                                unsigned int &tail) {
    pairs.clear();
    hasTail = false;
    tail = 0;
    size_t i = 0;
    size_t n = input.size();
    while (i < n - 1) {
        unsigned int a = input[i];
        unsigned int b = input[i + 1];
        VectorPair pair;
        if (a < b) {
            pair.loser = a;
            pair.winner = b;
        } else {
            pair.loser = b;
            pair.winner = a;
        }
        pair.hasLoser = true;
        pairs.push_back(pair);
        i += 2;
    }
    if (i < n) {
        hasTail = true;
        tail = input[i];
    }
}

// 2. sort winners
void PmergeMe::v_sortWinners(std::vector<VectorPair> &pairs) {

}


void PmergeMe::v_mergeInsert(std::vector<unsigned int> &data) {

}


void PmergeMe::v_makeChain(const std::vector<VectorPair> &pairs,
                                bool hasTail,
                                unsigned int tail,
                                std::vector<unsigned int> &chain) {

}
void PmergeMe::v_insertLosers(const std::vector<unsigned int> &chain,
                                    const std::vector<VectorPair> &pairs) {

}
void PmergeMe::v_computeOrder(size_t m, std::vector<size_t> &order) {

}
void PmergeMe::v_insert(std::vector<unsigned int> &a,
                            unsigned int x,
                            size_t hiExclusive) {

}
size_t PmergeMe::v_pos(const std::vector<unsigned int> &a, unsigned int value) {
    return 0;
}


//deque
void PmergeMe::d_mergeInsert(std::deque<unsigned int> &data) {

}
void PmergeMe::d_getPairs(const std::deque<unsigned int> &input, 
                                std::vector<DequePair> &pairs, 
                                bool &hasTail, 
                                unsigned int &tail) {

}
void PmergeMe::d_sortWinners(std::vector<DequePair> &pairs) {

}
void PmergeMe::d_makeChain(const std::vector<DequePair> &pairs,
                                bool hasTail,
                                unsigned int tail,
                                std::deque<unsigned int> &chain) {

}
void PmergeMe::d_insertLosers(const std::deque<unsigned int> &chain,
                                    const std::vector<DequePair> &pairs) {

}
void PmergeMe::d_computeOrder(size_t m, std::vector<size_t> &order) {

}
void PmergeMe::d_insert(std::deque<unsigned int> &a,
                            unsigned int x,
                            size_t hiExclusive) {

}
size_t PmergeMe::d_pos(const std::deque<unsigned int> &a, unsigned int value) {
    return 0;
}



void PmergeMe::generateUpTo(size_t limits, std::vector<size_t> &x) {}