#ifndef PMERGE_HPP
# define PMERGE_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <sys/time.h>

class PmergeMe {
    public:
        static void sortVector(std::vector<unsigned int> &v);
        static void sortDeque(std::deque<unsigned int> &d);

        static void now(struct timeval &tv);
        static double timeDiff(const struct timeval &a, const struct timeval &b);
    private:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe& operator=(const PmergeMe &other);
        ~PmergeMe();

        //vector
        struct VectorPair {
            unsigned int winner;
            bool hasLoser;
            unsigned int loser;
            VectorPair(): winner(0), hasLoser(false), loser(0) {}
        };
        static void v_mergeInsert(std::vector<unsigned int> &data);
        static void v_getPairs(const std::vector<unsigned int> &input, 
                                std::vector<VectorPair> &pairs, 
                                bool &hasTail, 
                                unsigned int &tail);
        static void v_sortWinners(std::vector<VectorPair> &pairs);
        static void v_makeChain(const std::vector<VectorPair> &pairs,
                                bool hasTail,
                                unsigned int tail,
                                std::vector<unsigned int> &chain);
        static void v_insertLosers(const std::vector<unsigned int> &chain,
                                    const std::vector<VectorPair> &pairs);
        static void v_computeOrder(size_t m, std::vector<size_t> &order);
        static void v_insert(std::vector<unsigned int> &a,
                            unsigned int x,
                            size_t hiExclusive);
        size_t v_pos(const std::vector<unsigned int> &a, unsigned int value);



        //deque
        struct DequePair {
            unsigned int winner;
            bool hasLoser;
            unsigned int loser;
            DequePair(): winner(0), hasLoser(false), loser(0) {}
        };
        static void d_mergeInsert(std::deque<unsigned int> &data);
        static void d_getPairs(const std::deque<unsigned int> &input, 
                                std::vector<DequePair> &pairs, 
                                bool &hasTail, 
                                unsigned int &tail);
        static void d_sortWinners(std::vector<DequePair> &pairs);
        static void d_makeChain(const std::vector<DequePair> &pairs,
                                bool hasTail,
                                unsigned int tail,
                                std::deque<unsigned int> &chain);
        static void d_insertLosers(const std::deque<unsigned int> &chain,
                                    const std::vector<DequePair> &pairs);
        static void d_computeOrder(size_t m, std::vector<size_t> &order);
        static void d_insert(std::deque<unsigned int> &a,
                            unsigned int x,
                            size_t hiExclusive);
        static size_t d_pos(const std::deque<unsigned int> &a, unsigned int value);



        static void generateUpTo(size_t limits, std::vector<size_t> &x);
};

#endif