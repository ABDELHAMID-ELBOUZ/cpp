#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cerrno>
#include <cctype>
#include <stdexcept>
#include <algorithm>


BitcoinExchange::BitcoinExchange()
{
    std::ifstream file("data.csv");
    if (!file.is_open())
        throw std::runtime_error("Error: could not open database.");

    std::string line;
    while (std::getline(file, line))
	{
        size_t sep = line.find(',');
		if (sep == std::string::npos)
			continue;

		std::string date = line.substr(0, sep);
		std::string rateStr = line.substr(sep + 1);
        _trim(date);
        _trim(rateStr);

        if (date == "date" || date.empty() || rateStr.empty())
            continue;

        char* endptr = NULL;
        errno = 0;
        double rate = std::strtod(rateStr.c_str(), &endptr);
        while (*endptr != '\0' && std::isspace(*endptr))
            ++endptr;
        if (*endptr != '\0' || errno == ERANGE)
            continue;

        _data[date] = static_cast<float>(rate);
    }
    file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _data(other._data)
{

}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        _data = other._data;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	
}


std::string& BitcoinExchange::_trim(std::string& s)
{
    size_t start = 0;
    while (start < s.length() && std::isspace(s[start]))
        ++start;
    size_t end = s.length();
    while (end > start && std::isspace(s[end - 1]))
        --end;
    s = s.substr(start, end - start);
    return s;
}

bool BitcoinExchange::_isValidDate(const std::string& date)
{
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;

    for (size_t i = 0; i < 10; ++i)
	{
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return false;
    }

    int year  = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day   = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (isLeap)
        daysInMonth[2] = 29;

    if (day > daysInMonth[month])
        return false;

    return true;
}

bool BitcoinExchange::_parseValue(const std::string& valueStr, float& outValue)
{
    if (valueStr.empty())
        return false;

    char* endptr = NULL;
    errno = 0;
    double val = std::strtod(valueStr.c_str(), &endptr);

    while (*endptr != '\0' && std::isspace(*endptr))
        ++endptr;

    if (*endptr != '\0')
        return false;
    if (errno == ERANGE)
        return false;
    if (val != val)
        return false;

    outValue = static_cast<float>(val);
    return true;
}

float BitcoinExchange::_getRate(const std::string& date) const
{
    std::map<std::string, float>::const_iterator it = _data.lower_bound(date);

    if (it != _data.end() && it->first == date)
        return it->second;

    if (it == _data.begin())
        throw std::runtime_error("no earlier date");

    --it;
    return it->second;
}


void BitcoinExchange::evaluate(const std::string& filename) const
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
	{
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line))
	{
        std::string originalLine = line;

        if (_trim(line).empty())
            continue;

        size_t sep = line.find('|');
        if (sep == std::string::npos)
		{
            std::cerr << "Error: bad input => " << originalLine << std::endl;
            continue;
        }

        std::string date = line.substr(0, sep);
        std::string valueStr = line.substr(sep + 1);

        _trim(date);
        _trim(valueStr);

        if (date == "date")
            continue;

        if (date.empty() || valueStr.empty())
		{
            std::cerr << "Error: bad input => " << originalLine << std::endl;
            continue;
        }

        if (!_isValidDate(date))
		{
            std::cerr << "Error: bad input => " << originalLine << std::endl;
            continue;
        }

        float value;
        if (!_parseValue(valueStr, value))
		{
            std::cerr << "Error: bad input => " << originalLine << std::endl;
            continue;
        }

        if (value < 0)
		{
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }

        if (value > 1000)
		{
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        float rate;
        try
		{
            rate = _getRate(date);
        }
		catch (...)
		{
            std::cerr << "Error: bad input => " << originalLine << std::endl;
            continue;
        }

        std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
    }

    file.close();
}