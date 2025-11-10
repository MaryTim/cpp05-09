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

        static void generateJacobsthalUpTo(size_t limit, std::vector<size_t> &js);

        //vector
        struct VectorPair {
            unsigned int winner;
            unsigned int loser;
            VectorPair(): winner(0), loser(0) {}
            VectorPair(unsigned int a, unsigned int b) : winner(a > b ? a : b), loser(a > b ? b : a) {}
        };

        struct VectorLevel {
            std::vector<VectorPair> pairs;
            bool hasTail;
            unsigned int tail;
            VectorLevel(): hasTail(false), tail(0) {}
        };

        static void v_mergeInsert(std::vector<unsigned int> &data);
        static void v_getPairs(const std::vector<unsigned int> &input, VectorLevel &l);
        static void v_buildWinners(const VectorLevel& l, std::vector<unsigned int> &out);
        static void v_reorderPairsByWinners(std::vector<VectorPair> &pairs, const std::vector<unsigned int> &chain);
        static void v_makeChain(const VectorLevel &l, std::vector<unsigned int> &chain);
        static void v_computeJacobsthalOrder(size_t m, std::vector<size_t> &order);
        static void v_insertValue(std::vector<unsigned int> &a,
                            unsigned int x,
                            size_t hiExclusive);
        static size_t v_pos(const std::vector<unsigned int> &a, unsigned int value);



        //deque
        struct DequePair {
            unsigned int winner;
            unsigned int loser;
            DequePair(): winner(0), loser(0) {}
            DequePair(unsigned int a, unsigned int b) : winner(a > b ? a : b), loser(a > b ? b : a) {}
        };

        struct DequeLevel {
            std::vector<DequePair> pairs;
            bool hasTail;
            unsigned int tail;
            DequeLevel(): hasTail(false), tail(0) {}
        };
        static void d_mergeInsert(std::deque<unsigned int> &data);
        static void d_getPairs(const std::deque<unsigned int> &input, DequeLevel &l);
        static void d_buildWinners(const DequeLevel &l, std::deque<unsigned int> &out);
        static void d_reorderPairsByWinners(std::vector<DequePair> &pairs, const std::deque<unsigned int> &chain);
        static void d_makeChain(const DequeLevel &l,std::deque<unsigned int> &chain);
        static void d_computeJacobsthalOrder(size_t m, std::vector<size_t> &order);
        static void d_insert(std::deque<unsigned int> &a, unsigned int x, size_t hiExclusive);
        static size_t d_pos(const std::deque<unsigned int> &a, unsigned int x);



        static void generateUpTo(size_t limits, std::vector<size_t> &x);
};

#endif