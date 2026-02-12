#include "../header/Bureaucrat.hpp"
#include "../header/AForm.hpp"
#include "../header/ShrubberyCreationForm.hpp"
#include "../header/PresidentialPardonForm.hpp"
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

	// AForm tests
	std::cout << "\n=== AForm Tests ===" << std::endl;
	Bureaucrat high("HighRank", 2);
	Bureaucrat lowRank("LowRank", 150);
	try {
		AForm *taxForm = new ShrubberyCreationForm("whatever");
		std::cout << *taxForm;
		std::cout << "AForm signed status: " << taxForm->getSignedStatus() << std::endl;
		std::cout << "Sign permission level: " << taxForm->getSignPermission() << std::endl;
		std::cout << "Exec permission level: " << taxForm->getExecPermission() << std::endl;
		
		Bureaucrat wow("john causes leaks?", 170); // no
		
		std::cout << "\nTrying to sign with grade " << high.getGrade() << " (need " << taxForm->getSignPermission() << ")..." << std::endl;
		lowRank.signForm(*taxForm);
		delete taxForm;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		AForm *restrictedForm = new PresidentialPardonForm("A_Restricted_Form");
		std::cout << "\nTrying to sign with grade " << lowRank.getGrade() << " (need " << restrictedForm->getSignPermission() << ")..." << std::endl;
		lowRank.signForm(*restrictedForm);
		std::cout << "\nTrying to sign with grade " << high.getGrade() << " (need " << restrictedForm->getSignPermission() << ")..." << std::endl;
		high.signForm(*restrictedForm); // works because AForm throws an exeption not Bureaucrat
		delete restrictedForm;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}