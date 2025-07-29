#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./a.out <literal>" << std::endl;
		return (1);
	}
	std::string s = argv[1];
	ScalarConverter::convert(s);
	return (0);
}
