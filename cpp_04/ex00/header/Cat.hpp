#pragma once

#include "Animal.hpp"

class Cat : virtual public Animal
{
	private:
		std::string type;
	public:
		Cat();
		Cat(const Cat &input);
		Cat& operator=(const Cat &input);
		~Cat();
		void	makeSound(void) const;
		const std::string&	getType(void) const;
};