#include "../header/Dog.hpp"
#include <iostream>

void Dog::makeSound() const {
	std::cout << "Woof Woof!" << std::endl;
}

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog default constructor called" <<  std::endl;
	this->brain = new Brain("Dog Food");
}

Dog::Dog(const Dog &input) : Animal(input) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain = new Brain(*input.brain);
	*this = input;
}

Dog& Dog::operator=(const Dog &input) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	Animal::operator=(input);
	delete this->brain;
	this->brain = new Brain(*input.brain);
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}