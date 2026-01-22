#include "../header/Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	this->fixedPointValue = 0;
	std::cout << "default constructor called" << std::endl;
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

int Fixed::toInt(void) const
{
	return (this->fixedPointValue >> this->fractionalBits);
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->fixedPointValue) / (1 << this->fractionalBits));
}

Fixed::Fixed(const int raw)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPointValue = raw << this->fractionalBits;
}

Fixed::Fixed(const float raw)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedPointValue = static_cast<int>(roundf(raw * (1 << this->fractionalBits)));
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

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}