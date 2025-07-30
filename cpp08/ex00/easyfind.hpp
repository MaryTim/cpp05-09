#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iterator> 
#include <iostream>

template<typename T>
typename T::iterator easyfind(T& container, int number) {
    typename T::iterator it = std::find(container.begin(), container.end(), number);
    if (it == container.end()) {
        throw std::runtime_error("Number not found\n");
    }
    return it;
}

#endif