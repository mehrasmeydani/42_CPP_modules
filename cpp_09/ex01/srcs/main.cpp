#include "../header/RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2)
	{
		print_error("invalid input");
		return (1);
	}
	std::istringstream in(argv[1]);
	RPN	rpn;
	try {
		rpn.calc(in);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}