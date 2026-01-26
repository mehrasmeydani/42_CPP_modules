#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : virtual public Animal
{
	private:
		Brain* brain;
	public:
		Dog();
		Dog(const Dog &input);
		Dog& operator=(const Dog &input);
		~Dog();
		void makeSound() const;
};