#include "../header/WrongAnimal.hpp"
#include <iostream>

void	WrongAnimal::makeSound(void) const {
	std::cout << "Random WrongAnimal sound!" << std::endl;
}

const std::string& WrongAnimal::getType(void) const{
	return this->type;	
}

WrongAnimal::WrongAnimal() : type("RANDOM WRONGANIMAL") {
	std::cout << "WrongAnimal default constructor called" <<  std::endl;
}

WrongAnimal::WrongAnimal(const std::string &name) : type(name) {
	std::cout << "WrongAnimal parameterized constructor called" <<  std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &input) {
	std::cout << "WrongAnimal copy constructor called" <<  std::endl;
	*this = input;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &input) {
	std::cout << "WrongAnimal copy assignment operator called" <<  std::endl;
	this->type = input.type;
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" <<  std::endl;
}

