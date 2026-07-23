#include "ScalarConverter.hpp"
#include <iostream>
// #include <cstdlib>
#include <cctype>
#include <cmath>
#include <limits>
#include <iomanip>
#include <cerrno>

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
}

ScalarConverter::~ScalarConverter()
{

}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return *this;
}

void ScalarConverter::convert(const std::string& literal)
{
	if (literal == "nan" || literal == "+inf" || literal == "-inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << literal << 'f' << std::endl;
		std::cout << "double: " << literal << std::endl;
		return ;
	}
	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << literal << std::endl;
		std::cout << "double: " << literal.substr(0, literal.length()-1) << std::endl;
		return ;
	}
    e_type type = detectType(literal);

    if (type == TYPE_INVALID)
	{
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    if (type == TYPE_CHAR)
	{
        char c = literal[1];
        printChar(static_cast<int>(c));
        printInt(static_cast<int>(c));
        printFloat(static_cast<float>(c));
        printDouble(static_cast<double>(c));
    }
	else if (type == TYPE_INT)
	{
        long long ll = strtoll(literal.c_str(), NULL, 10);
        printChar(ll);
        if (ll > std::numeric_limits<int>::max() || ll < std::numeric_limits<int>::min())
            std::cout << "int: impossible" << std::endl;
        else
            printInt(static_cast<int>(ll));
        printFloat(static_cast<float>(ll));
        printDouble(static_cast<double>(ll));
    }
	else if (type == TYPE_FLOAT)
	{
		errno = 0;
		float f = strtof(literal.c_str(), NULL);
		if (errno == ERANGE)
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return ;
		}
		printChar(static_cast<int>(f));
		double d = static_cast<double>(f);
		if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
			std::cout << "int: impossible" << std::endl;
		else
			printInt(static_cast<int>(f));
		printFloat(f);
		printDouble(static_cast<double>(f));
	}
	else if (type == TYPE_DOUBLE)
	{
		errno = 0;
		double d = strtod(literal.c_str(), NULL);
		if (errno == ERANGE)
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return ;		
		}
		printChar(static_cast<int>(d));
		if (d > static_cast<double>(std::numeric_limits<int>::max()) || d < static_cast<double>(std::numeric_limits<int>::min()))
			std::cout << "int: impossible" << std::endl;
		else
			printInt(static_cast<int>(d));
		printFloat(static_cast<float>(d));
		printDouble(d);
	}
}

bool ScalarConverter::isValidFloat(const std::string& s)
{
    if (s.length() < 4)
        return false;
    if (s[s.length() - 1] != 'f')
        return false;

    std::string num = s.substr(0, s.length() - 1);
    if (num.empty() || num == "-" || num == "+")
        return false;

    size_t dotPos = num.find('.');
    if (dotPos == std::string::npos)
        return false;

    std::string beforeDot = num.substr(0, dotPos);
    std::string afterDot = num.substr(dotPos + 1);

    if (beforeDot.empty() || afterDot.empty())
        return false;
    if (beforeDot == "-" || beforeDot == "+")
        return false;

    char* end;
    strtod(num.c_str(), &end);
    return *end == '\0';
}

bool ScalarConverter::isValidDouble(const std::string& s)
{
    if (s.find('.') == std::string::npos)
        return false;

    size_t dotPos = s.find('.');
    std::string beforeDot = s.substr(0, dotPos);
    std::string afterDot = s.substr(dotPos + 1);

    if (beforeDot.empty() || afterDot.empty())
        return false;
    if (beforeDot == "-" || beforeDot == "+")
        return false;

    char* end;
    strtod(s.c_str(), &end);
    return *end == '\0';
}

ScalarConverter::e_type ScalarConverter::detectType(const std::string& s)
{
    if (s.length() == 3 && s[0] == '\'' && s[2] == '\'')
        return TYPE_CHAR;

    if (s.find(' ') != std::string::npos)
        return TYPE_INVALID;

    if (s.length() >= 4 && (s[s.length() - 1] == 'f'))
	{
        if (isValidFloat(s))
            return TYPE_FLOAT;
    }

    if (isValidDouble(s))
        return TYPE_DOUBLE;

    if (!s.empty())
	{
        size_t i = 0;
        if (s[0] == '-' || s[0] == '+')
            i++;
        if (i < s.length()) {
            bool allDigits = true;
            for (; i < s.length(); i++)
			{
                if (!std::isdigit(s[i]))
				{
                    allDigits = false;
                    break;
                }
            }
            if (allDigits)
                return TYPE_INT;
        }
    }

    return TYPE_INVALID;
}

void ScalarConverter::printChar(int c)
{
	if (c < 0 || c > 127)
            std::cout << "char: impossible" << std::endl;
    if (std::isprint(c))
        std::cout << "char: '" << static_cast<char>(c) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::printInt(int i)
{
    std::cout << "int: " << i << std::endl;
}

void ScalarConverter::printFloat(float f)
{
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void ScalarConverter::printDouble(double d)
{
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}
