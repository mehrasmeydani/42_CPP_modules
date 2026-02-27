#include "../header/whatever.hpp"
#include <iostream>

int main( void ) {
	std::cout << "========================================\n";
	std::cout << "    Template Functions Test (ex00)\n";
	std::cout << "========================================\n\n";

	// Test with integers
	std::cout << "--- Integer Tests ---\n";
	int a = 2;
	int b = 3;
	std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << "After swap:  a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::cout << "\n";

	// Test with strings
	std::cout << "--- String Tests ---\n";
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "Before swap: c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "After swap:  c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	std::cout << "\n";

	// Test with floats
	std::cout << "--- Float Tests ---\n";
	float e = 3.14f;
	float f = 2.71f;
	std::cout << "Before swap: e = " << e << ", f = " << f << std::endl;
	::swap(e, f);
	std::cout << "After swap:  e = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;
	std::cout << "\n";

	// Test with doubles
	std::cout << "--- Double Tests ---\n";
	double g = 42.42;
	double h = 21.21;
	std::cout << "Before swap: g = " << g << ", h = " << h << std::endl;
	::swap(g, h);
	std::cout << "After swap:  g = " << g << ", h = " << h << std::endl;
	std::cout << "min( g, h ) = " << ::min( g, h ) << std::endl;
	std::cout << "max( g, h ) = " << ::max( g, h ) << std::endl;
	std::cout << "\n";

	// Test with chars
	std::cout << "--- Char Tests ---\n";
	char i = 'a';
	char j = 'z';
	std::cout << "Before swap: i = " << i << ", j = " << j << std::endl;
	::swap(i, j);
	std::cout << "After swap:  i = " << i << ", j = " << j << std::endl;
	std::cout << "min( i, j ) = " << ::min( i, j ) << std::endl;
	std::cout << "max( i, j ) = " << ::max( i, j ) << std::endl;
	std::cout << "\n";

	// Edge case: equal values
	std::cout << "--- Edge Case: Equal Values ---\n";
	int x = 42;
	int y = 42;
	std::cout << "x = " << x << ", y = " << y << std::endl;
	std::cout << "min( x, y ) = " << ::min( x, y ) << std::endl;
	std::cout << "max( x, y ) = " << ::max( x, y ) << std::endl;
	std::cout << "\n";

	std::cout << "========================================\n";
	return 0;
}