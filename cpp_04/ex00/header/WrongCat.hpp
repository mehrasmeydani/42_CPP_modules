#pragma once

#include "WrongAnimal.hpp"

class WrongCat : virtual public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat &input);
		WrongCat& operator=(const WrongCat &input);
		~WrongCat();
		void	makeSound(void) const;
};