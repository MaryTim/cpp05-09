#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : rates_(other.rates_) {}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other)
        rates_ = other.rates_;
    return *this;
}
BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isLeapYear(int y) {
    return ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));
}

int BitcoinExchange::daysInMonth(int y, int m) {
    const int daysForMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (m == 2)
        return (daysForMonth[1] + (isLeapYear(y) ? 1 : 0));
    if (m >= 1 && m <= 12)
        return daysForMonth[m-1];
    return 0;
}

bool BitcoinExchange::isDigitStr(std::string &s) {
    if (s.empty())
        return false;
    for (std::string::size_type i = 0; i < s.size(); i++)
        if (!std::isdigit(s[i]))
            return false;
    return true;
}

bool BitcoinExchange::parseDate(std::string& s, int& y, int& m, int& d) {
    if (s.size() != 10 || s[4] != '-' || s[7] != '-')
        return false;
    std::string year = s.substr(0,4);
    std::string month = s.substr(5,2);
    std::string day = s.substr(8,2);
    if (!isDigitStr(year) || !isDigitStr(month) || !isDigitStr(day))
        return false;
    y = std::atoi(year.c_str());
    m = std::atoi(month.c_str());
    d = std::atoi(day.c_str());
    if (m < 1 || m > 12)
        return false;
    int dim = daysInMonth(y, m);
    if (d < 1 || d > dim)
        return false;
    return true;
}

std::string BitcoinExchange::trim(std::string &s) {
    int first = 0;
    int last = s.size();
    while (first < last && std::isspace(s[first]))
        first++;
    while (last > first && std::isspace(s[last-1]))
        last--;
    return s.substr(first, last - first);
}

bool BitcoinExchange::split(std::string &line, char sep, std::string &left, std::string &right) {
    std::string::size_type i = line.find(sep);
    if (i == std::string::npos) //not found
        return false;
    left = line.substr(0, i);
    right = line.substr(i + 1);
    return true;
}

bool BitcoinExchange::parsePositiveVal(std::string& s, double& out) {
    char* endptr = 0; //receicve address of first unparsed char
    out = std::strtod(s.c_str(), &endptr);
    if (endptr == s.c_str()) //if string can´t be convertred to double, endptr is set to s
        return false;
    if (out < 0.0) {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (out > 1000.0) {
        std::cerr << "Error: number is too big" << std::endl;
        return false;
    }
    return true;
}

bool BitcoinExchange::findRate(std::string& date, double& rateOut) {
    std::map<std::string,double>::iterator it = rates_.lower_bound(date);
    if (it == rates_.end()) { // all keys in map are less than date
        if (rates_.empty())
            return false;
        it--;
        rateOut = it->second;
        return true;
    }
    if (it->first == date) {
        rateOut = it->second;
        return true;
    }
    if (it == rates_.begin())
        return false;
    it--;
    rateOut = it->second;
    return true;
}

void BitcoinExchange::proccessFile(const std::string &filename) {
    std::ifstream fin(filename.c_str());
    if (!fin.good()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    std::string line;
    while (std::getline(fin, line)) {
        if (line.empty())
            continue;
        std::string t = trim(line);

        std::string left;
        std::string right;
        if (!split(line, '|', left, right)) {
            std::cerr << "Error: bad input => " << trim(line) << std::endl;
            continue;
        }
        std::string date = trim(left);
        std::string value = trim(right);
        int year;
        int month;
        int day;
        if (!parseDate(date, year, month, day)) {
            std::cerr << "Bad date parsing => " << trim(line) << std::endl;
            continue;
        }
        double amount = 0.0;
        if (!parsePositiveVal(value, amount))
            continue;
        double rate = 0.0;
        if (!findRate(date, rate)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        double result = amount * rate;
        std::cout << date << " => " << amount << " = " << result << std::endl;
    }
}

bool BitcoinExchange::loadDB(const std::string& filename) {
    std::ifstream fin(filename.c_str());
    if (!fin.good())
        return false;

    std::string line;

    while (std::getline(fin, line)) {
        if (line.empty())
            continue;
        std::string date;
        std::string price;

        if (!split(line, ',', date, price))
            continue;
        date = trim(date);
        price = trim(price);
        int y;
        int m;
        int d;
        if (!parseDate(date, y, m, d))
            continue;
        char* e = 0;
        double rate = std::strtod(price.c_str(), &e);
        if (e == price.c_str())
            continue;
        rates_[date] = rate;
    }
    return !rates_.empty();
}