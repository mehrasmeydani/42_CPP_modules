#include <iostream>
#include "../header/Point.hpp"

void testBSP(Point const &a, Point const &b, Point const &c, Point const &point, bool expected)
{
	bool result = bsp(a, b, c, point);
	std::cout << "Point " << point << " in triangle " << a << ", " << b << ", " << c 
			  << " => " << (result ? "INSIDE" : "OUTSIDE") 
			  << " (expected: " << (expected ? "INSIDE" : "OUTSIDE") << ") "
			  << (result == expected ? "✓" : "✗") << "\n";
}

int main(void)
{
	std::cout << "=== BSP Triangle Test Suite ===\n\n";

	// Test 1: Basic triangle with positive coordinates
	std::cout << "--- Test 1: Basic triangle (0,0) (10,0) (5,10) ---\n";
	Point a1(0, 0);
	Point b1(10, 0);
	Point c1(5, 10);
	
	testBSP(a1, b1, c1, Point(5, 5), true);        // Center - should be inside
	testBSP(a1, b1, c1, Point(15, 5), false);      // Far outside
	testBSP(a1, b1, c1, Point(5, 0), false);       // On edge (bottom)
	testBSP(a1, b1, c1, Point(0, 0), false);       // On vertex A
	testBSP(a1, b1, c1, Point(10, 0), false);      // On vertex B
	testBSP(a1, b1, c1, Point(5, 10), false);      // On vertex C
	testBSP(a1, b1, c1, Point(5.1f, 0.1f), true);  // Just inside
	testBSP(a1, b1, c1, Point(2.6f, 5), true);     // Inside left
	testBSP(a1, b1, c1, Point(7.4f, 5), true);     // Inside right

	// Test 2: Negative coordinates
	std::cout << "\n--- Test 2: Negative coordinates (-5,-5) (5,-5) (0,5) ---\n";
	Point a2(-5, -5);
	Point b2(5, -5);
	Point c2(0, 5);
	
	testBSP(a2, b2, c2, Point(0, 0), true);        // Center - should be inside
	testBSP(a2, b2, c2, Point(-5, -5), false);     // On vertex A
	testBSP(a2, b2, c2, Point(5, -5), false);      // On vertex B
	testBSP(a2, b2, c2, Point(0, 5), false);       // On vertex C
	testBSP(a2, b2, c2, Point(0, -5), false);      // On bottom edge
	testBSP(a2, b2, c2, Point(-2.4f, 0), true);    // Inside left half
	testBSP(a2, b2, c2, Point(2.4f, 0), true);     // Inside right half
	testBSP(a2, b2, c2, Point(0, -10), false);     // Below triangle
	testBSP(a2, b2, c2, Point(0, 10), false);      // Above triangle

	// Test 3: All negative coordinates
	std::cout << "\n--- Test 3: All negative coordinates (-10,-10) (-10,-5) (-5,-7.5) ---\n";
	Point a3(-10, -10);
	Point b3(-10, -5);
	Point c3(-5, -7.5f);
	
	testBSP(a3, b3, c3, Point(-8.33f, -7.5f), true);   // Inside
	testBSP(a3, b3, c3, Point(-10, -7.5f), false);     // On left edge
	testBSP(a3, b3, c3, Point(-5, -7.5f), false);      // On vertex C
	testBSP(a3, b3, c3, Point(0, 0), false);           // Far outside

	// Test 4: Mixed positive/negative
	std::cout << "\n--- Test 4: Mixed coordinates (-3,2) (3,-2) (0,5) ---\n";
	Point a4(-3, 2);
	Point b4(3, -2);
	Point c4(0, 5);
	
	testBSP(a4, b4, c4, Point(0, 1), true);        // Inside center
	testBSP(a4, b4, c4, Point(0.1f, 0.1f), true);        // Inside near base
	testBSP(a4, b4, c4, Point(-3, 2), false);      // On vertex
	testBSP(a4, b4, c4, Point(1.5f, 1.4f), true);  // Inside right
	testBSP(a4, b4, c4, Point(1.5f, 1.5f), false);  // On edge
	testBSP(a4, b4, c4, Point(-1.5f, 1.5f), true); // Inside left

	std::cout << "\n=== Tests Complete ===\n";

	return 0;
}
