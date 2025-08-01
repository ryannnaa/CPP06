#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(0));

	Base *p = generate();
	Base *b = new Base();

	std::cout << "[ Pointer Identification ]" << std::endl;
	identify(p);

	std::cout << "\n[ Reference Identification ]" << std::endl;
	identify(*p);

	std::cout << "\n[ Base class Identification ]" << std::endl;
	identify(b);
	identify(*b);

	delete p;
	delete b;

	return (0);
}
