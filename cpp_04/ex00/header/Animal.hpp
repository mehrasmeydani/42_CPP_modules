#pragma once

#include <string>

class Animal
{
	private:
		std::string type;
	public:
		Animal();
		Animal(const std::string &name);
		Animal(const Animal &in);
		Animal& operator=(const Animal &in);
		void	makeSound(void);
};