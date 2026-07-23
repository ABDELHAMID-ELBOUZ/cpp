#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
public:
    static void convert(const std::string& literal);

private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

    enum e_type { TYPE_CHAR, TYPE_INT, TYPE_FLOAT, TYPE_DOUBLE, TYPE_INVALID };

    static e_type detectType(const std::string& s);
    static bool isValidFloat(const std::string& s);
    static bool isValidDouble(const std::string& s);
    static void printChar(int c);
    static void printInt(int i);
    static void printFloat(float f);
    static void printDouble(double d);
};

#endif