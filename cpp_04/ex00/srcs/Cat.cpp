#include "../header/Cat.hpp"
#include <iostream>

void	Cat::makeSound(void) const
{
	std::cout << "Meow Meow!" << std::endl;
}

const	std::string& Cat::getType(void)const {
	return this->type;
}

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor called" <<  std::endl;
}
Cat::Cat(const Cat &input) : Animal(input)
{
	std::cout << "Cat copy constructor called" <<  std::endl;
	*this = input;
}

Cat& Cat::operator=(const Cat &input)
{
	std::cout << "Cat copy assignment operator called" <<  std::endl;
	Animal::operator=(input);
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" <<  std::endl;
}