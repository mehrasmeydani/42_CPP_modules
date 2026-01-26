#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : virtual public Animal
{
	private:
		Brain* brain;
	public:
		Cat();
		Cat(const Cat &input);
		Cat& operator=(const Cat &input);
		~Cat();
		void	makeSound(void) const;
};