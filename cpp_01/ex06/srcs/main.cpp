#include "../header/Harl.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	Harl harl;

	if (argc < 2)
	{
		std::cout << "Give me something to complain about." << std::endl;
		return (1);
	}
	harl.complain(argv[1]);
	return 0;
}