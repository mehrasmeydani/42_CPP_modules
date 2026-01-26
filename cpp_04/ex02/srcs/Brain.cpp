#include "../header/Brain.hpp"
#include <iostream>

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		ideas[i] = "Food";
	}
}

Brain::Brain(const Brain &input) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = input;
}

Brain::Brain(std::string idea) {
	std::cout << "Brain parameterized constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		ideas[i] = idea;
	}
}

Brain& Brain::operator=(const Brain &input) {
	std::cout << "Brain copy assignment operator called" << std::endl;
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = input.ideas[i];
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}