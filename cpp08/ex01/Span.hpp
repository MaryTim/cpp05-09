#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <stdexcept>

class Span {
    public:
        Span();
        Span(unsigned int quantity);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int number);
        int shortestSpan() const;
        int longestSpan() const;

        template<typename I>
        void addRange(I begin, I end) {
        if (std::distance(begin, end) + numbers_.size() > quantity_)
            throw std::runtime_error("Range exceeds max size");
        numbers_.insert(numbers_.end(), begin, end);
    }
    private:
        unsigned int quantity_;
        std::vector<int> numbers_;
};

#endif