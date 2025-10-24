#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main() {
    std::vector<int> v;
    v.push_back(10);
    v.push_back(12);
    v.push_back(17);
    std::list<int> l;
    l.push_back(5);
    l.push_back(15);
    l.push_back(25);
    std::deque<int> d;
    d.push_back(30);
    d.push_back(31);
    d.push_front(33);

    try {
        std::vector<int>::iterator it = easyfind(v, 12);
        std::cout << "Found in vector: " << *it << "\n";
    } catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    try {
        std::list<int>::iterator lit = easyfind(l, 15);
        std::cout << "Found in list: " << *lit << "\n";
    } catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    try { 
        easyfind(v, 100);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    try { 
        easyfind(d, 33);
        std::cout << "Found element in deque" << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
    return 0;
}