#include "ScalarConverter.hpp"

ScalarConverter:: ScalarConverter()
{
	
}

ScalarConverter:: ScalarConverter(ScalarConverter &other)
{
	(void)other;
}

ScalarConverter& ScalarConverter:: operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter:: ~ScalarConverter()
{
	
}

bool ScalarConverter::isChar(const std::string &str)
{
    return (str.length() == 1 && str[0] >= 32 && str[0] <= 126);
}

bool ScalarConverter::isInt(const std::string &str)
{
    std::stringstream ss(str);
    int i;
    ss >> i;
    return !ss.fail() && ss.eof();
}

bool ScalarConverter::isFloat(const std::string &str)
{
    if (str == "inff" || str == "+inff" || str == "-inff" || str == "nanf")
    {
        return true;
    }
    std::stringstream ss(str);
    float f;
    ss >> f;
    return !ss.fail() && ss.eof();
}

bool ScalarConverter::isDouble(const std::string &str)
{
    if (str == "inf" || str == "+inf" || str == "-inf" || str == "nan")
    {
        return true;
    }
    std::stringstream ss(str);
    double d;
    ss >> d;
    return !ss.fail() && ss.eof();
}

void ScalarConverter::printChar(char value)
{
    if (value >= 32 && value <= 126)
    {
        std::cout << "char: '" << value << "'" << std::endl;
    }
    else
    {
        std::cout << "char: Non displayable" << std::endl;
    }
}

void ScalarConverter::printInt(int value)
{
    std::cout << "int: " << value << std::endl;
}

void ScalarConverter::printFloat(float value)
{
    if (value == std::numeric_limits<float>::infinity())
        std::cout << "float: +inf" << std::endl;
    else if (value == -std::numeric_limits<float>::infinity())
        std::cout << "float: -inf" << std::endl;
    else if (std::isnan(value))
        std::cout << "float: nanf" << std::endl;
    else
        std::cout << "float: " << value << "f" << std::endl;
}

void ScalarConverter::printDouble(double value) 
{
    if (value == std::numeric_limits<double>::infinity())
        std::cout << "double: +inf" << std::endl;
    else if (value == -std::numeric_limits<double>::infinity())
        std::cout << "double: -inf" << std::endl;
    else if (std::isnan(value))
        std::cout << "double: nan" << std::endl;
    else
        std::cout << "double: " << value << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
    if (isChar(literal))
    {
        char c = literal[0];
        printChar(c);
        printInt(static_cast<int>(c));
        printFloat(static_cast<float>(c));
        printDouble(static_cast<double>(c));
    } 
    else if (isInt(literal))
    {
        std::stringstream ss(literal);
        int i;
        ss >> i;
        printChar(static_cast<char>(i));
        printInt(i);
        printFloat(static_cast<float>(i));
        printDouble(static_cast<double>(i));
    }
    else if (isFloat(literal))
    {
        std::stringstream ss(literal);
        float f;
        ss >> f;
        printChar(static_cast<char>(f));
        printInt(static_cast<int>(f));
        printFloat(f);
        printDouble(static_cast<double>(f));
    }
    else if (isDouble(literal))
    {
        std::stringstream ss(literal);
        double d;
        ss >> d;
        printChar(static_cast<char>(d));
        printInt(static_cast<int>(d));
        printFloat(static_cast<float>(d));
        printDouble(d);
    }
    else
    {
        std::cout << "Invalid input" << std::endl;
    }
}
