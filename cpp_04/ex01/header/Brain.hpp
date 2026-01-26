#pragma once

#include <string>

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain &input);
		Brain(std::string idea);
		Brain& operator=(const Brain &input);
		~Brain();
};