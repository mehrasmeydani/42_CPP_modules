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
		virtual const std::string& getType(void) const;
		virtual ~Animal() = 0;
		virtual void	makeSound(void) const = 0;
};