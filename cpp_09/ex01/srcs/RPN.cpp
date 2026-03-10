#include "../header/RPN.hpp"

void	RPN::calc(std::istringstream &in) {
	size_t					pos;
	std::string				token;
	const std::string		str = "+-*/";

	while (in >> token) {
		if (token.length() > 1)
			throw std::runtime_error("invalid input");
		if (std::isdigit(token[0]))
			this->nums.push(token[0] - '0');
		else if ((pos = str.find(token, 0)) != std::string::npos && this->nums.size() >= 2)
		{
			int tmp = nums.top();
			nums.pop();
			switch (pos) {
				case 0:
					tmp = nums.top() + tmp;
					nums.pop();
					nums.push(tmp);
					break;
				case 1:
					tmp = nums.top() - tmp;
					nums.pop();
					nums.push(tmp);
					break;
				case 2:
					tmp = nums.top() * tmp;
					nums.pop();
					nums.push(tmp);
					break;
				case 3:
					if (tmp != 0)
					{
						tmp = nums.top() / tmp;
						nums.pop();
						nums.push(tmp);
						break;
					}
					else
						throw std::runtime_error("division by zero");
			}
		}
		else
			throw std::runtime_error("Error");
	}
	if (nums.size() != 1)
		throw std::runtime_error("Error");
	std::cout << nums.top() << std::endl;
}

RPN::RPN(void) {}

RPN::RPN(const RPN& in) {(void)in;}

RPN &RPN::operator=(const RPN& in) {
	(void)in;
	return (*this);
}

RPN::~RPN(void) {}

void print_error(const std::string &err) {
	std::cerr << err << std::endl;
}
