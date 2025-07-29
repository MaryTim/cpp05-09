#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdexcept>

template<typename T>
class Array {
    public:
        Array() : data_(NULL), size_(0) {}
        Array(unsigned int n) : data_(NULL), size_(n) {
            if (n > 0) {
                data_ = new T[n];
                for (unsigned int i = 0; i < n; i++) {
                    data_[i] = T();
                }
            }
        }
        Array(const Array& other) : data_(NULL), size_(other.size_) {
            if (size_ > 0) {
                data_ = new T[size_];
                for (unsigned int i = 0; i < size_; i++) {
                    data_[i] = other.data_[i];
                }
            }
        }
        Array& operator=(const Array& other) {
            if (this != &other) {
                delete[] data_;

                size_ = other.size_;
                if (size_ > 0) {
                    data_ = new T[size_];
                } else {
                    data_ = NULL;
                }
                for (unsigned int i = 0; i < size_; i++)
                    data_[i] = other.data_[i];
            }
            return *this;
        }
        ~Array() {
            delete[] data_;
        }

        unsigned int size() {
            return size_;
        }

        T& operator[](unsigned int index) {
            if (index >= size_)
                throw std::out_of_range("Index out of bounds");
            return data_[index];
        }
    private:
        T* data_;
        unsigned int size_;
};

#endif