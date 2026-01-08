#include <iostream>
#include "../header/Fixed.hpp"

int main(void)
{
	// Subject-provided baseline tests
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;        // 0
	std::cout << ++a << std::endl;      // 0.00390625 (1 raw step)
	std::cout << a << std::endl;        // same as above
	std::cout << a++ << std::endl;      // prints current, then increments
	std::cout << a << std::endl;        // incremented value
	std::cout << b << std::endl;        // 10.1016

	// max/min using static overloads
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;
	

	// Comparison operators
	std::cout << "(a < b): " << (a < b) << std::endl;
	std::cout << "(a > b): " << (a > b) << std::endl;
	std::cout << "(a <= b): " << (a <= b) << std::endl;
	std::cout << "(a >= b): " << (a >= b) << std::endl;
	std::cout << "(a == b): " << (a == b) << std::endl;
	std::cout << "(a != b): " << (a != b) << std::endl;

	// Pre/Post decrement tests
	std::cout << --a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;

	// Arithmetic operators (multiplication/division implemented via toFloat)
	Fixed c(10);       // 10.0
	Fixed d(2.5f);     // 2.5
	std::cout << "c: " << c << ", d: " << d << std::endl;
	std::cout << "c * d: " << (c * d) << std::endl;
	std::cout << "c / d: " << (c / d) << std::endl;

	// min/max overloads
	std::cout << "min(c, d): " << Fixed::min(c, d) << std::endl;
	std::cout << "max(c, d): " << Fixed::max(c, d) << std::endl;

	// Conversion helpers
	Fixed e(42.42f);
	std::cout << "e: " << e << ", e.toInt(): " << e.toInt() << std::endl;

	return 0;
}