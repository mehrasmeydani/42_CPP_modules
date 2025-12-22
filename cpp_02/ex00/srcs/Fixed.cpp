#include "../header/Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
	this->fixedPointValue = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &input)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = input;
}

Fixed& Fixed::operator=(const Fixed &input)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixedPointValue = input.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	this->fixedPointValue = raw;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}