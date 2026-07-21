#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <limits>
#include <iomanip>

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
    e_type type = detectType(literal);

    if (type == TYPE_INVALID)
	{
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    double d = 0.0;
    if (type == TYPE_CHAR)
        d = static_cast<double>(literal[1]);
    else
        d = std::strtod(literal.c_str(), NULL);

    toChar(d);
    toInt(d);
    toFloat(d);
    toDouble(d);
}

ScalarConverter::e_type ScalarConverter::detectType(const std::string& s)
{
    if (s.length() == 3 && s[0] == '\'' && s[2] == '\'')
        return TYPE_CHAR;

    if (s.find(' ') != std::string::npos)
        return TYPE_INVALID;

    if (s == "nan" || s == "inf" || s == "+inf" || s == "-inf")
        return TYPE_DOUBLE;

    if (s == "nanf" || s == "inff" || s == "+inff" || s == "-inff")
        return TYPE_FLOAT;

    if (s.length() >= 2 && (s[s.length() - 1] == 'f' || s[s.length() - 1] == 'F'))
	{
        std::string num = s.substr(0, s.length() - 1);
        if (!(num.empty() || num == "-" || num == "+"))
		{
            char* end;
            std::strtod(num.c_str(), &end);
            if (*end == '\0')
                return TYPE_FLOAT;
        }
    }

    if (s.find('.') != std::string::npos)
	{
        char* end;
        std::strtod(s.c_str(), &end);
        if (*end == '\0')
            return TYPE_DOUBLE;
    }

    if (!s.empty())
	{
        size_t i = 0;
        if (s[0] == '-' || s[0] == '+')
            i++;
        if (i < s.length())
		{
            bool allDigits = true;
            for (; i < s.length(); i++)
			{
                if (!std::isdigit(static_cast<unsigned char>(s[i])))
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

void ScalarConverter::toChar(double d)
{
    if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
	{
        std::cout << "char: impossible" << std::endl;
        return;
    }
    char c = static_cast<char>(d);
    if (std::isprint(static_cast<unsigned char>(c)))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::toInt(double d)
{
    if (std::isnan(d) || std::isinf(d) || d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
	{
        std::cout << "int: impossible" << std::endl;
        return;
    }
    std::cout << "int: " << static_cast<int>(d) << std::endl;
}

void ScalarConverter::toFloat(double d)
{
    float f = static_cast<float>(d);
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void ScalarConverter::toDouble(double d)
{
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}
