#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <limits>
#include <iomanip>
#include <cmath>
#include <cctype>

class ScalarConverter
{
	public:
	    ScalarConverter();
	    ScalarConverter(const ScalarConverter& other);
	    ScalarConverter& operator=(const ScalarConverter& other);
	    ~ScalarConverter();
	
	    static void convert(const std::string& literal);
};

#endif
