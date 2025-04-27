#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}
ScalarConverter::ScalarConverter(const ScalarConverter&) 
{
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&)
{
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

static bool isPseudoLiteral(const std::string& s)
{
    return s == "nan"  || s == "nanf" ||
           s == "+inf" || s == "+inff"||
           s == "-inf" || s == "-inff";
}
static bool isCharLiteral(const std::string& s)
{
    return s.size() == 1 && !std::isdigit(s[0]);
}

static bool parseValue(const std::string& lit, double& out)
{
    if (isCharLiteral(lit))
    {
        out = static_cast<double>(lit[0]);
        return true;
    }
    if (isPseudoLiteral(lit))
    {
        return true;
    }

    std::stringstream ss(lit);
    if (!lit.empty() && lit[lit.size()-1] == 'f')
    {
        ss.str(lit.substr(0, lit.size()-1));
    }
    if (!(ss >> out) || !ss.eof()) {
        return false;
    }
    return true;
}

static void printChar(double v, bool pseudo)
{
    std::cout << "char: ";
    if (pseudo || v < std::numeric_limits<char>::min() || v > std::numeric_limits<char>::max())
    {
        std::cout << "impossible\n";
    }
    else if (!std::isprint(static_cast<char>(v)))
    {
        std::cout << "Non displayable\n";
    }
    else
    {
        std::cout << "'" << static_cast<char>(v) << "'\n";
    }
}
static void printInt(double v, bool pseudo)
{
    std::cout << "int: ";
    if (pseudo || v < std::numeric_limits<int>::min() || v > std::numeric_limits<int>::max())
    {
        std::cout << "impossible\n";
    }
    else
    {
        std::cout << static_cast<int>(v) << "\n";
    }
}
static void printFloat(double v, const std::string& lit)
{
    std::cout << "float: " << std::fixed << std::setprecision(1);

    if (lit == "nan"  || lit == "nanf") std::cout << "nanf\n";
    else if (lit == "+inf"|| lit == "+inff") std::cout << "+inff\n";
    else if (lit == "-inf"|| lit == "-inff") std::cout << "-inff\n";
    else std::cout << static_cast<float>(v) << "f\n";
}

static void printDouble(double v, const std::string& lit)
{
    std::cout << "double: ";
    
    if (lit == "nan"  || lit == "nanf")   std::cout << "nan\n";
    else if (lit == "+inf"|| lit == "+inff") std::cout << "+inf\n";
    else if (lit == "-inf"|| lit == "-inff") std::cout << "-inf\n";
    else std::cout << v << "\n";
}

void ScalarConverter::convert(const std::string& literal)
{
    double value = 0.0;
    bool pseudo = isPseudoLiteral(literal);

    if (!parseValue(literal, value))
    {
        std::cout
            << "char: impossible\n"
            << "int: impossible\n"
            << "float: impossible\n"
            << "double: impossible\n";
        return;
    }

    printChar(value, pseudo);
    printInt(value, pseudo);
    printFloat(value, literal);
    printDouble(value, literal);
}
