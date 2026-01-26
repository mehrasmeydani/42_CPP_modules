#pragma once

#include <string>

class RandomAnimal
{
	private:
		std::string type;
	public:
		RandomAnimal();
		RandomAnimal(const std::string &name);
		RandomAnimal(const RandomAnimal &in);
		RandomAnimal& operator=(const RandomAnimal &in);
		virtual const std::string& getType(void) const;
		virtual ~RandomAnimal();
		virtual void	makeSound(void) const;
};