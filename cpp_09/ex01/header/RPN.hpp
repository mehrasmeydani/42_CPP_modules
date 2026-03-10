#pragma once

#include <stack>
#include <sstream>
#include <iostream>

class RPN {
	private:
		RPN(const RPN& in);
		RPN& operator=(const RPN& in);
		std::stack<int>	nums;

	public:
		RPN(void);
		~RPN();
		void	calc(std::istringstream &in);
};

void print_error(const std::string &err);
