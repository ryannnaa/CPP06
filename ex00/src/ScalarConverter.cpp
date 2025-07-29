#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <cctype>

static bool isPseudo(const std::string& literal)
{
	return (literal == "-inff" || literal == "+inff" || literal == "nanf" || literal == "-inf" || literal == "+inf" || literal == "nan");
}

static bool isDisplayable(char c)
{
	return (std::isprint(static_cast<unsigned char>(c)));
}

static void printLiteral(bool isPseu, double value)
{
	std::cout << "char: ";
	if (isPseu || value < 0 || value > 127)
		std::cout << "impossible" << std::endl;
	else if (isDisplayable(static_cast<char>(value)))
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	std::cout << "int: ";
	if (isPseu || value < static_cast<double>(std::numeric_limits<int>::min()) || value > static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;

	std::cout << "float: ";
	std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;

	std::cout << std::fixed << std::setprecision(1) << value << std::endl;
}

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	if (this != &other)
	{
		;
	}
	return (*this);
}

ScalarConverter::~ScalarConverter()
{}

void ScalarConverter::convert(std::string& literal)
{
	double value = 0.0;
	bool isPseu = isPseudo(literal);

	if (literal.length() == 1 && !std::isdigit(literal[0]))
	{
		char c = literal[0];
		value = static_cast<double>(c);
	}
	else if (isPseu)
	{
		if (literal == "-inff" || literal == "-inf")
			value = -std::numeric_limits<double>::infinity();
		else if (literal == "+inff" || literal == "+inf")
			value = std::numeric_limits<double>::infinity();
		else if (literal == "nanf" || literal == "nan")
			value = std::numeric_limits<double>::quiet_NaN();
	}
	else
	{
		char *end = NULL;
		value = std::strtod(literal.c_str(), &end);
		if (end && *end == 'f' && *(end + 1) == '\0')
		{
			;
		}
		else if (end && *end != '\0')
		{
			std::cerr << "Invalid literal." << std::endl;
			return ;
		}
	}
	printLiteral(isPseu, value);
}
