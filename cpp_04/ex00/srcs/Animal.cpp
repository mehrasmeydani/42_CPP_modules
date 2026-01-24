#include "../header/Animal.hpp"
#include <iostream>

void	Animal::makeSound(void) const
{
	std::cout << "Random Animal sound!" << std::endl;
}

const std::string& Animal::getType(void) const
{
	return this->type;	
}

Animal::Animal() : type("RANDOM ANIMAL")
{
	std::cout << "Animal default constructor called" <<  std::endl;
}

Animal::Animal(const std::string &name) : type(name)
{
	std::cout << "Animal parameterized constructor called" <<  std::endl;
}

Animal::Animal(const Animal &input)
{
	std::cout << "Animal copy constructor called" <<  std::endl;
	*this = input;
}

Animal& Animal::operator=(const Animal &input)
{
	std::cout << "Animal copy assignment operator called" <<  std::endl;
	this->type = input.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" <<  std::endl;
}