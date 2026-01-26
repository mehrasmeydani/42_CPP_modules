#include "../header/Cat.hpp"
#include <iostream>

void	Cat::makeSound(void) const{
	std::cout << "Meow Meow!" << std::endl;
}

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat default constructor called" <<  std::endl;
	brain = new Brain("Cat Food");
}

Cat::Cat(const Cat &input) : Animal(input){
	std::cout << "Cat copy constructor called" <<  std::endl;
	brain = new Brain(*input.brain);
	*this = input;
}

Cat& Cat::operator=(const Cat &input){
	std::cout << "Cat copy assignment operator called" <<  std::endl;
	Animal::operator=(input);
	delete this->brain;
	this->brain = new Brain(*input.brain);
	return (*this);
}

Cat::~Cat(){
	std::cout << "Cat destructor called" <<  std::endl;
	delete brain;
}