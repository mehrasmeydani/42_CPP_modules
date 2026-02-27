#include "../header/Base.hpp"
#include "../header/A.hpp"
#include "../header/B.hpp"
#include "../header/C.hpp"
#include <iostream>
#include <cstdlib>

Base * generate(void) {
	int i = rand();
	if (i % 3 == 0)
		return new A;
	else if (i % 3 == 1)
		return new B;
	else
		return new C;
}

void	identify(Base* p) {
	std::cout << "Pointer Points to ";
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "A class!\n";
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "B class!\n";
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "C class!\n";
	else
		std::cout << "some other class!\n";
}

void	identify(Base& p) {
	std::cout << "Reference References ";
	try {
		(void)dynamic_cast<A &>(p);	
		std::cout << "A class!\n";
	} catch (const std::exception &e) {
		(void)e;
	}
	try {
		(void)dynamic_cast<B &>(p);	
		std::cout << "B class!\n";
	} catch (const std::exception &e) {
		(void)e;
	}
	try {
		(void)dynamic_cast<C &>(p);	
		std::cout << "C class!\n";
	} catch (const std::exception &e) {
		(void)e;
	}
}

int main() {
	srand(time(0));
	std::cout << "========================================\n";
	std::cout << "       Type Identification Test\n";
	std::cout << "========================================\n\n";

	std::cout << "--- Manual Tests (without generate) ---\n\n";

	std::cout << "Creating A:\n";
	Base *a = new A;
	identify(a);
	identify(*a);
	delete a;
	std::cout << "\n";

	std::cout << "Creating B:\n";
	Base *b = new B;
	identify(b);
	identify(*b);
	delete b;
	std::cout << "\n";

	std::cout << "Creating C:\n";
	Base *c = new C;
	identify(c);
	identify(*c);
	delete c;
	std::cout << "\n";

	std::cout << "--- Random Tests (using generate) ---\n\n";
	for (int i = 0; i < 5; i++) {
		std::cout << "Random #" << (i + 1) << ":\n";
		Base *r = generate();
		identify(r);
		identify(*r);
		delete r;
		std::cout << "\n";
	}

	std::cout << "--- Edge Case Tests ---\n\n";

	std::cout << "NULL pointer:\n";
	Base *null_ptr = NULL;
	identify(null_ptr);
	std::cout << "\n";

	std::cout << "Pointer reassignment (A -> B -> C):\n";
	Base *ptr = new A;
	std::cout << "After new A: ";
	identify(ptr);
	delete ptr;
	ptr = new B;
	std::cout << "After new B: ";
	identify(ptr);
	delete ptr;
	ptr = new C;
	std::cout << "After new C: ";
	identify(ptr);
	delete ptr;
	std::cout << "\n";

	std::cout << "Multiple objects at once:\n";
	Base *arr[3];
	arr[0] = new A;
	arr[1] = new B;
	arr[2] = new C;
	for (int i = 0; i < 3; i++) {
		std::cout << "arr[" << i << "]: ";
		identify(arr[i]);
	}
	for (int i = 0; i < 3; i++)
		delete arr[i];
	std::cout << "\n";

	std::cout << "========================================\n";
}