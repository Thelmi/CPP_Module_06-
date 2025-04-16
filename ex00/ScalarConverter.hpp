#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <sstream>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter &other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

		static bool isChar(const std::string &str);
		static bool isInt(const std::string &str);
		static bool isFloat(const std::string &str);
		static bool isDouble(const std::string &str);
		
		static void printChar(char value);
		static void printInt(int value);
		static void printFloat(float value);
		static void printDouble(double value);
	public:
		static void convert(const std::string &literal);
};

#endif

