#include <iostream>
#include <string>
#include "../header/Fixed.hpp"

static void header(const std::string& label)
{
	std::cout << "\n-- " << label << " --" << std::endl;
}

int main(void)
{
	// Subject-provided baseline tests

	Fixed a;
	const Fixed b(Fixed(5.05f) * Fixed(2));

	header("pre/post increment");
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;

	header("min/max statics");
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;

	header("comparisons");
	std::cout << "(a < b): " << (a < b) << std::endl;
	std::cout << "(a > b): " << (a > b) << std::endl;
	std::cout << "(a <= b): " << (a <= b) << std::endl;
	std::cout << "(a >= b): " << (a >= b) << std::endl;
	std::cout << "(a == b): " << (a == b) << std::endl;
	std::cout << "(a != b): " << (a != b) << std::endl;

	header("pre/post decrement");
	std::cout << --a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;

	header("arithmetic");
	Fixed c(10);
	Fixed d(2.5f);
	std::cout << "c: " << c << ", d: " << d << std::endl;
	std::cout << "c * d: " << (c * d) << std::endl;
	std::cout << "c / d: " << (c / d) << std::endl;

	header("min/max overloads");
	std::cout << "min(c, d): " << Fixed::min(c, d) << std::endl;
	std::cout << "max(c, d): " << Fixed::max(c, d) << std::endl;

	header("conversion helper");
	Fixed e(42.42f);
	std::cout << "e: " << e << ", e.toInt(): " << e.toInt() << std::endl << "\n\n";

	Fixed g;
	Fixed const h( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << g << std::endl;
	std::cout << ++g << std::endl;
	std::cout << g << std::endl;
	std::cout << g++ << std::endl;
	std::cout << g << std::endl;
	std::cout << h << std::endl;
	std::cout << Fixed::max( g, h ) << std::endl;
	return 0;

	return 0;
}