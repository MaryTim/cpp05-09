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

void PmergeMe::sortDeque(std::deque<unsigned int> &d) {
    d_mergeInsert(d);
}

// (0,1,1,3,5,11,...)
void PmergeMe::generateJacobsthalUpTo(size_t limit, std::vector<size_t> &js) {
    js.clear();
    js.push_back(0);
    js.push_back(1);
    while (true) {
        size_t a = js[js.size() - 1];
        size_t b = js[js.size() - 2];
        size_t next = a + 2*b;
        if (next > limit)
            break;
        js.push_back(next);
    }
}

// vector

// - repeatedly pair input and replace with winners until size <= 1
// - at each level reorder pairs by already-sorted chain,
// build main chain from winners (+ tail), then insert losers in
// Jacobsthal order (each loser bounded by its own winner position)
void PmergeMe::v_mergeInsert(std::vector<unsigned int> &data) {
    if (data.size() <= 1)
        return;

    std::vector<VectorLevel> stack;
    std::vector<unsigned int> a = data;
    while (a.size() > 1) {
        VectorLevel l;
        v_getPairs(a, l);
        stack.push_back(l);
        v_buildWinners(l, a); // replace a with only winners
    }
    std::vector<unsigned int> chain = a;
    for (long s = static_cast<long>(stack.size()) - 1; s >= 0; s--) {
        VectorLevel &l = stack[static_cast<size_t>(s)];
        // Order pairs to match where their winners appear in the current chain
        v_reorderPairsByWinners(l.pairs, chain);
        v_makeChain(l, chain);
        // Insert each loser before its winner (bounded) in Jacobsthal order
        size_t m = l.pairs.size();
        std::vector<size_t> order;
        v_computeJacobsthalOrder(m, order);
        for (size_t t = 0; t < order.size(); t++) {
            size_t i = order[t];
            const VectorPair &p = l.pairs[i - 1];
            size_t wpos = v_pos(chain, p.winner);
            v_insertValue(chain, p.loser, wpos);
        }
    }
    data.swap(chain);
}

// make pairs from initial vector
void PmergeMe::v_getPairs(const std::vector<unsigned int> &input, VectorLevel &l) {
    l.pairs.clear();
    l.hasTail = false;
    l.tail = 0;
    size_t n = input.size();
    for (size_t i = 0; i + 1 < n; i += 2) {
        l.pairs.push_back(VectorPair(input[i], input[i+1]));
    }
    if (n % 2) { 
        l.hasTail = true;
        l.tail = input.back();
    }
}

// extract winner from each pair
void PmergeMe::v_buildWinners(const VectorLevel& l, std::vector<unsigned int> &out) {
    out.clear();
    for (size_t i = 0; i < l.pairs.size(); i++) {
        out.push_back(l.pairs[i].winner);
    }
}

// reorder pairs by ordered winners
void PmergeMe::v_reorderPairsByWinners(std::vector<VectorPair> &pairs, const std::vector<unsigned int> &chain) {
    std::vector<char> used(pairs.size(), 0);
    std::vector<VectorPair> out;

    for (size_t k = 0; k < chain.size(); k++) {
        unsigned int w = chain[k];
        for (size_t j = 0; j < pairs.size(); j++) {
            if (!used[j] && pairs[j].winner == w) {
                out.push_back(pairs[j]);
                used[j] = 1;
                break;
            }
        }
        if (out.size() == pairs.size()) {
            break;
        }
    }
    // append any leftover (shouldn't happen in correct flow).
    for (size_t j = 0; j < pairs.size(); j++) {
        if (!used[j]) {
            out.push_back(pairs[j]);
        }
    }
    pairs.swap(out);
}

//only winners
void PmergeMe::v_makeChain(const VectorLevel &l, std::vector<unsigned int> &chain) {
    chain.clear();
    for (size_t i = 0; i < l.pairs.size(); i++) {
        chain.push_back(l.pairs[i].winner);
    }
    if (l.hasTail)
        v_insertValue(chain, l.tail, chain.size());
}

void PmergeMe::v_computeJacobsthalOrder(size_t m, std::vector<size_t> &order) {
    order.clear();
    if (m == 0)
        return;

    std::vector<size_t> j;
    generateJacobsthalUpTo(m, j);

    size_t prev = 1; 
    for (size_t k = 2; k < j.size(); k++) {
        size_t curr = j[k];
        size_t start = prev + 1;
        size_t end = curr;
        if (end > m) end = m;
        if (start <= end) {
            for (size_t idx = end;; idx--) {
                order.push_back(idx);
                if (idx == start)
                    break;
            }
        }
        prev = curr;
    }
    if (prev < m) {
        for (size_t idx = m;; idx--) {
            order.push_back(idx);
            if (idx == prev + 1)
                break;
        }
    }
    // Ensure index 1 exists
    bool has1 = false;
    for (size_t i = 0; i < order.size(); i++)
        if (order[i] == 1) {
            has1 = true;
            break;
        }
    if (!has1)
        order.insert(order.begin(), 1);
}

void PmergeMe::v_insertValue(std::vector<unsigned int> &a, unsigned int x, size_t hiExclusive) {
    size_t start = 0;
    size_t end = hiExclusive;
    while (start < end) {
        size_t mid = (start + end) / 2;
        if (a[mid] < x) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    //insert x into the vector at position end, shifting later elements to the right
    a.insert(a.begin() + static_cast<long>(end), x);
}

size_t PmergeMe::v_pos(const std::vector<unsigned int> &a, unsigned int x) {
    for (size_t i = 0; i < a.size(); i++)
        if (a[i] == x)
            return i;
    return a.size();
}





//deque
void PmergeMe::d_mergeInsert(std::deque<unsigned int> &data) {
    if (data.size() <= 1)
        return;
    std::vector<DequeLevel> stack;
    std::deque<unsigned int> a = data;
    while (a.size() > 1) {
        DequeLevel l;
        d_getPairs(a, l);
        stack.push_back(l);
        d_buildWinners(l, a);
    }

    std::deque<unsigned int> chain = a;
    for (long s = static_cast<long>(stack.size()) - 1; s >= 0; s--) {
        DequeLevel &l = stack[static_cast<size_t>(s)];

        d_reorderPairsByWinners(l.pairs, chain);
        d_makeChain(l, chain);
        size_t m = l.pairs.size();
        std::vector<size_t> order;
        d_computeJacobsthalOrder(m, order);
        for (size_t t = 0; t < order.size(); t++) {
            size_t i = order[t];
            const DequePair &p = l.pairs[i - 1];
            size_t wpos = d_pos(chain, p.winner);
            d_insert(chain, p.loser, wpos);
        }
    }
    data.swap(chain);
}

void PmergeMe::d_getPairs(const std::deque<unsigned int> &input, DequeLevel &l) {
    l.pairs.clear();
    l.hasTail = false;
    l.tail = 0;
    size_t n = input.size();
    for (size_t i = 0; i + 1 < n; i += 2) {
        l.pairs.push_back(DequePair(input[i], input[i+1]));
    }
    if (n % 2) {
        l.hasTail = true;
        l.tail = input.back();
    }
}

void PmergeMe::d_buildWinners(const DequeLevel &l, std::deque<unsigned int> &out) {
    out.clear();
    for (size_t i = 0; i < l.pairs.size(); i++) {
        out.push_back(l.pairs[i].winner);
    }
}

void PmergeMe::d_makeChain(const DequeLevel &l, std::deque<unsigned int> &chain) {
    chain.clear();
    for (size_t i = 0; i < l.pairs.size(); i++) {
        chain.push_back(l.pairs[i].winner);
    }
    if (l.hasTail) {
        d_insert(chain, l.tail, chain.size());
    }
}

void PmergeMe::d_reorderPairsByWinners(std::vector<DequePair>& pairs, const std::deque<unsigned int> &chain) {
    std::vector<char> used(pairs.size(), 0);
    std::vector<DequePair> out; out.reserve(pairs.size());

    for (size_t k = 0; k < chain.size(); k++) {
        unsigned int w = chain[k];
        for (size_t j = 0; j < pairs.size(); j++) {
            if (!used[j] && pairs[j].winner == w) {
                out.push_back(pairs[j]);
                used[j] = 1;
                break;
            }
        }
        if (out.size() == pairs.size())
            break;
    }
    for (size_t j = 0; j < pairs.size(); ++j)
        if (!used[j]) {
            out.push_back(pairs[j]);
        }

    pairs.swap(out);
}

void PmergeMe::d_computeJacobsthalOrder(size_t m, std::vector<size_t> &order) {
    order.clear();
    if (m == 0)
        return;
    std::vector<size_t> j;
    generateJacobsthalUpTo(m, j);

    size_t prev = 1;
    for (size_t k = 2; k < j.size(); k++) {
        size_t curr = j[k];
        size_t start = prev + 1;
        size_t end = curr;
        if (end > m) {
            end = m;
        }
        if (start <= end) {
            for (size_t idx = end;; idx--) {
                order.push_back(idx);
                if (idx == start)
                    break;
            }
        }
        prev = curr;
    }
    if (prev < m) {
        for (size_t idx = m;; idx--) {
            order.push_back(idx);
            if (idx == prev + 1)
                break;
        }
    }
    bool has1 = false;
    for (size_t i = 0; i < order.size(); i++) {
        if (order[i] == 1) {
            has1 = true;
            break;
        }
    }
    if (!has1) {
        order.insert(order.begin(), 1);
    }
}

void PmergeMe::d_insert(std::deque<unsigned int> &a, unsigned int x, size_t hiExclusive) {
    size_t start = 0;
    size_t end = hiExclusive;
    while (start < end) {
        size_t mid = (start + end) / 2;
        if (a[mid] < x) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    //insert x into the vector at position end, shifting later elements to the right
    a.insert(a.begin() + static_cast<long>(end), x);
}

size_t PmergeMe::d_pos(const std::deque<unsigned int> &a, unsigned int x) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] == x)
            return i;
    }
    return a.size();
}
