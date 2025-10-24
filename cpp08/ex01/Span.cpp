#include "Span.hpp"
#include <iostream>
#include <algorithm>


Span::Span() : quantity_(10) {
    std::cout << "Default constructor for a span has been called \n";
}

Span::Span(unsigned int quantity) : quantity_(quantity) {
    std::cout << "Constructor for a span with the quantity " << quantity_ << " has been called \n";
}

Span::Span(const Span& other) : quantity_(other.quantity_), numbers_(other.numbers_) {
    std::cout << "Copy constructor for a span with the quantity " << quantity_ << " has been called \n";
}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        quantity_ = other.quantity_;
        numbers_ = other.numbers_;
    }
    return *this;
}

Span::~Span() {
    std::cout << "Destructor for a span has been called \n";
}

void Span::addNumber(int number) {
    if (numbers_.size() >= quantity_)
        throw std::runtime_error("Span is full");
    numbers_.push_back(number);
}

int Span::shortestSpan() const {
    if (numbers_.size() < 2)
        throw std::runtime_error("Not enough numbers for a span");
    std::vector<int> sorted = numbers_;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = sorted[1] - sorted[0];
    for (size_t i = 2; i < sorted.size(); i++) {
        int diff = sorted[i] - sorted[i - 1];
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}

int Span::longestSpan() const {
    if (numbers_.size() < 2)
        throw std::runtime_error("Not enough numbers for a span");

    int min = *std::min_element(numbers_.begin(), numbers_.end());
    int max = *std::max_element(numbers_.begin(), numbers_.end());
    return max - min;
}