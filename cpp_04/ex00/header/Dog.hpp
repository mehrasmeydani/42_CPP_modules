#pragma once
#include "Animal.hpp"

class Dog : public Animal
{
	private:
		std::string type;
	public:
		Dog();
		Dog(const Dog &input);
		Dog& operator=(const Dog &input);
		~Dog();
};