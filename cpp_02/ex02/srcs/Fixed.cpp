#include "../header/Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed& Fixed::operator=(const Fixed &input)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	this->fixedPointValue = input.getRawBits();
	return (*this);
}

/*********	operrator comparisons	*********/

bool	Fixed::operator<(const Fixed &input) const
{
	if (this->fixedPointValue < input.fixedPointValue)
		return (true);
	return (false);
}

bool	Fixed::operator>(const Fixed &input) const
{
	if (this->fixedPointValue > input.fixedPointValue)
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed &input) const
{
	if (this->fixedPointValue <= input.fixedPointValue)
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed &input) const
{
	if (this->fixedPointValue >= input.fixedPointValue)
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed &input) const
{
	if (this->fixedPointValue == input.fixedPointValue)
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed &input) const
{
	if (this->fixedPointValue != input.fixedPointValue)
		return (true);
	return (false);
}

/*********	operrator values	*********/

Fixed&	Fixed::operator++(void)
{
	this->fixedPointValue = this->fixedPointValue + 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	old = *this;
	operator++();
	return (old);
}

Fixed&	Fixed::operator--(void)
{
	this->fixedPointValue = this->fixedPointValue - 1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	old = *this;
	operator--();
	return (old);
}

const Fixed	Fixed::operator+(const Fixed& input) const
{
	Fixed result;
	result.setRawBits(this->fixedPointValue + input.fixedPointValue);
	return result;
}


const Fixed	Fixed::operator-(const Fixed& input) const
{
	Fixed result;
	result.setRawBits(this->fixedPointValue - input.fixedPointValue);
	return result;
}

const Fixed	Fixed::operator*(const Fixed&input) const
{
	Fixed result;
	result.setRawBits((this->getRawBits() * input.getRawBits()) >> (this->fractionalBits));
	return (result);
}

const Fixed	Fixed::operator/(const Fixed&input) const
{
	Fixed result;
	result.setRawBits((this->getRawBits() / input.getRawBits()) << (this->fractionalBits));
	return (result);
}

/*********		operrator cout		*********/

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat() << std::flush;
	return os;
}

/*********		constructors		*********/

Fixed::Fixed(const float raw)
{
	//std::cout << "Float constructor called" << std::endl;
	this->fixedPointValue = static_cast<int>(roundf(raw * (1 << this->fractionalBits)));
}

Fixed::Fixed()
{
	//std::cout << "default constructor called" << std::endl;
	this->fixedPointValue = 0;
}

Fixed::Fixed(const Fixed &input)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = input;
}

Fixed::Fixed(const int raw)
{
	//std::cout << "Int constructor called" << std::endl;
	this->fixedPointValue = raw << this->fractionalBits;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

/*********		value manipulation	*********/

int Fixed::toInt(void) const
{
	return (this->fixedPointValue >> this->fractionalBits);
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->fixedPointValue) / (1 << this->fractionalBits));
}

int Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	this->fixedPointValue = raw;
}

/*********		value manipulation	*********/

const Fixed&	Fixed::min(const Fixed &input1, const Fixed &input2)
{
	return ((input1.fixedPointValue < input2.fixedPointValue) ? input1 : input2);
}

const Fixed&	Fixed::max(const Fixed &input1, const Fixed &input2)
{
	return ((input1.fixedPointValue > input2.fixedPointValue) ? input1 : input2);
}

Fixed&	Fixed::min(Fixed &input1, Fixed &input2)
{
	return ((input1 < input2) ? input1 : input2);
}

Fixed&	Fixed::max(Fixed &input1, Fixed &input2)
{
	return ((input1 > input2) ? input1 : input2);
}

