#pragma once

#include <string>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(const std::string &name);
		WrongAnimal(const WrongAnimal &input);
		WrongAnimal& operator=(const WrongAnimal &input);
		virtual ~WrongAnimal();
		virtual void	makeSound(void) const;
		virtual const std::string& getType(void) const;
};