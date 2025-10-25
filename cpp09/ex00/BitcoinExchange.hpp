#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <cstdlib>
# include <cctype>
# include <fstream>

class BitcoinExchange {
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        bool loadDB(const std::string &filename);
        void proccessFile(const std::string &filename);

    private:
        std::map<std::string, double> rates_;

        bool findRate(std::string &date, double &rate);
        static bool parseDate(std::string &s, int &Y, int &M, int &D);
        static std::string trim(std::string &s);
        static bool split(std::string &line, char sep, std::string &left, std::string &right);
        static bool parsePositiveVal(std::string &s, double &out);
        static bool isDigitStr(std::string &s);
        static int daysInMonth(int y, int m);
        static bool isLeapYear(int y);
        
};

#endif