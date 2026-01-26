#include "../header/Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor called" <<  std::endl;
}

Dog::Dog(const Dog &input) : Animal(input)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = input;
}

Dog& Dog::operator=(const Dog &input)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	Animal::operator=(input);
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof!" << std::endl;
}
