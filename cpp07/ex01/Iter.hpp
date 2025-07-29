#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

template<typename T, typename Func>
void iter(T* array, std::size_t size, Func func) {
    for (std::size_t i = 0; i < size; i++) {
        func(array[i]);
    }
}

#endif