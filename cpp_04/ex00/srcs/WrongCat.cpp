#include "../header/WrongCat.hpp"
#include <iostream>

void WrongCat::makeSound() const {
	std::cout << "Meow! (WrongCat sound)" << std::endl;
}

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &input) : WrongAnimal(input) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = input;
}

WrongCat& WrongCat::operator=(const WrongCat &input) {
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	WrongAnimal::operator=(input);
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}