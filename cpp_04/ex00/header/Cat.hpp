#pragma once

#include "Animal.hpp"

class Cat : virtual public Animal
{
	public:
		Cat();
		Cat(const Cat &input);
		Cat& operator=(const Cat &input);
		~Cat();
		void	makeSound(void) const;
};