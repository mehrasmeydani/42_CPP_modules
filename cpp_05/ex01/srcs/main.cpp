#include "../header/Bureaucrat.hpp"
#include <iostream>

int main() {
	try {
		Bureaucrat bob("Bob", 2);
		std::cout << bob;
		bob.incrementGrade();
		std::cout << bob;
		bob.incrementGrade(); // exception
		std::cout << bob; // stops here
		bob.decrementGrade();
		std::cout << bob;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat alice("Alice", 149);
		std::cout << alice;
		alice.decrementGrade();
		std::cout << alice;
		alice.decrementGrade(); // exception
		std::cout << alice; // stops here
		alice.incrementGrade();
		std::cout << alice;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}