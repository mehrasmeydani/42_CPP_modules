#include "../header/RandomAnimal.hpp"
#include <iostream>

void	RandomAnimal::makeSound(void) const {
	std::cout << "Random Animal sound!" << std::endl;
}

const std::string& RandomAnimal::getType(void) const{
	return this->type;	
}

RandomAnimal::RandomAnimal() : type("RANDOM ANIMAL") {
	std::cout << "RandomAnimal default constructor called" <<  std::endl;
}

RandomAnimal::RandomAnimal(const std::string &name) : type(name) {
	std::cout << "RandomAnimal parameterized constructor called" <<  std::endl;
}

RandomAnimal::RandomAnimal(const RandomAnimal &input) {
	std::cout << "RandomAnimal copy constructor called" <<  std::endl;
	*this = input;
}

RandomAnimal& RandomAnimal::operator=(const RandomAnimal &input) {
	std::cout << "RandomAnimal copy assignment operator called" <<  std::endl;
	this->type = input.type;
	return (*this);
}

RandomAnimal::~RandomAnimal() {
	std::cout << "RandomAnimal destructor called" <<  std::endl;
}