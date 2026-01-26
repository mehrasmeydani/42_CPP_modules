#pragma once

#include <string>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const std::string &name);
		Animal(const Animal &in);
		Animal& operator=(const Animal &in);
		virtual const std::string& getType(void) const;
		virtual ~Animal();
		virtual void	makeSound(void) const;
};