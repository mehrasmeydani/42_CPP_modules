#pragma once
#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &input);
		Dog& operator=(const Dog &input);
		~Dog();
		void makeSound() const;
};