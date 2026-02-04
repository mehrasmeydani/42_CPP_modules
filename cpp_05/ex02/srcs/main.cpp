#include "../header/Bureaucrat.hpp"
#include "../header/Form.hpp"
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

	// Form tests
	std::cout << "\n=== Form Tests ===" << std::endl;
	Bureaucrat high("HighRank", 2);
	Bureaucrat lowRank("LowRank", 100);
	try {
		Form taxForm("Tax Form", 25, 10);
		std::cout << taxForm;
		std::cout << "Form signed status: " << taxForm.getSignedStatus() << std::endl;
		std::cout << "Sign permission level: " << taxForm.getSignPermission() << std::endl;
		std::cout << "Exec permission level: " << taxForm.getExecPermission() << std::endl;

		std::cout << "\nTrying to sign with grade " << high.getGrade() << " (need " << taxForm.getSignPermission() << ")..." << std::endl;
		high.signForm(taxForm);
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		Form restrictedForm("Restricted Form", 3, 2);
		std::cout << "\nTrying to sign with grade " << lowRank.getGrade() << " (need " << restrictedForm.getSignPermission() << ")..." << std::endl;
		lowRank.signForm(restrictedForm);
		std::cout << "\nTrying to sign with grade " << high.getGrade() << " (need " << restrictedForm.getSignPermission() << ")..." << std::endl;
		high.signForm(restrictedForm); // works because form throws an exeption not Bureaucrat
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}