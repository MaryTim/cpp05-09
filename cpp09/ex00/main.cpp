#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "The program expects 1 extra argument(a file)" << std::endl;
        return 1;
    }
    BitcoinExchange btc;
    if (!btc.loadDB("data.csv")) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    btc.proccessFile(argv[1]);
    return 0;
}
