#include "../header/Bureaucrat.hpp"
#include "../header/AForm.hpp"
#include "../header/ShrubberyCreationForm.hpp"
#include "../header/PresidentialPardonForm.hpp"
#include "../header/RobotomyRequestForm.hpp"
#include "../header/Intern.hpp"
#include <iostream>
#include <cstdlib>

void testFormExecution(Bureaucrat& bureaucrat, AForm& form) {
	try {
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what();
	}
}

int main() {
	{
		srand(time(0));
		std::cout << "\n__________Creating Bureaucrats...__________\n";
		Bureaucrat highRank("HighRanker", 1);
		Bureaucrat midRank("MidRanker", 50);
		Bureaucrat lowRank("LowRanker", 150);

		std::cout << "\n__________Creating Forms...__________\n";
		ShrubberyCreationForm shrubbery("home");
		std::cout << "\n";
		RobotomyRequestForm robotomy("Alice");
		std::cout << "\n";
		PresidentialPardonForm pardon("Bob");

		std::cout << "\n__________Testing LowRanker...__________\n";
		testFormExecution(lowRank, shrubbery);
		testFormExecution(lowRank, robotomy);
		testFormExecution(lowRank, pardon);
		
		std::cout << "\n__________Testing MidRanker...__________\n";
		testFormExecution(midRank, shrubbery);
		std::cout << "\n";
		testFormExecution(midRank, robotomy);
		testFormExecution(midRank, pardon);
		
		std::cout << "\n__________Testing HighRanker...__________\n";
		testFormExecution(highRank, shrubbery);
		std::cout << "\n";
		testFormExecution(highRank, robotomy);
		std::cout << "\n";
		testFormExecution(highRank, robotomy);
		std::cout << "\n";
		testFormExecution(highRank, robotomy);
		std::cout << "\n";
		testFormExecution(highRank, pardon);
		std::cout << "\n";
		
		std::cout << "\n__________Deleting...__________\n";
	}
	{
		std::cout << "=== Test 1: Create Bureaucrats and Intern ===" << std::endl;
		Bureaucrat boss("Boss", 1);
		Bureaucrat mid("Mid", 50);
		Bureaucrat low("Low", 100);
		Bureaucrat lowest("Lowest", 150);
		Intern intern;

		std::cout << "\n=== Test 2: Intern creates valid forms ===" << std::endl;
		AForm* form1 = intern.makeForm("Robotomy Request", "Bender");
		AForm* form2 = intern.makeForm("Presidential Pardon", "Marvin");
		AForm* form3 = intern.makeForm("Shrubbery Creation", "garden");

		std::cout << "\n=== Test 3: Display created forms ===" << std::endl;
		if (form1) std::cout << *form1;
		if (form2) std::cout << *form2;
		if (form3) std::cout << *form3;

		std::cout << "\n=== Test 4: Intern tries to create invalid form ===" << std::endl;
		AForm* invalid = intern.makeForm("invalid form name", "target");
		std::cout << "Invalid form pointer is: " << (invalid ? "not NULL" : "NULL") << std::endl;

		std::cout << "\n=== Test 5: Bureaucrat signs forms created by intern ===" << std::endl;
		boss.signForm(*form1);
		boss.signForm(*form2);
		boss.signForm(*form3);

		std::cout << "\n=== Test 6: Bureaucrat executes forms created by intern ===" << std::endl;
		boss.executeForm(*form1);
		boss.executeForm(*form2);
		boss.executeForm(*form3);

		std::cout << "\n=== Test 7: Mid-grade bureaucrat tries forms ===" << std::endl;
		mid.signForm(*form1);
		mid.executeForm(*form1);

		std::cout << "\n=== Test 8: Low-grade bureaucrat cannot execute high-grade forms ===" << std::endl;
		low.signForm(*form3);
		low.executeForm(*form3);

		std::cout << "\n=== Test 9: Test all form types separately ===" << std::endl;
		AForm* robotomy = intern.makeForm("Robotomy Request", "C3PO");
		AForm* pardon = intern.makeForm("Presidential Pardon", "Prisoner");
		AForm* shrubbery = intern.makeForm("Shrubbery Creation", "park");

		std::cout << "\nRobotomy form created:" << std::endl;
		boss.signForm(*robotomy);
		std::cout << "Executing robotomy 3 times for testing:" << std::endl;
		for (int i = 0; i < 3; i++) {
			boss.executeForm(*robotomy);
		}

		std::cout << "\nPardon form created:" << std::endl;
		boss.signForm(*pardon);
		boss.executeForm(*pardon);

		std::cout << "\nShrubbery form created:" << std::endl;
		boss.signForm(*shrubbery);
		boss.executeForm(*shrubbery);

		std::cout << "\n=== Test 10: Try various invalid form names ===" << std::endl;
		intern.makeForm("", "target");
		intern.makeForm("robotomy", "target");
		intern.makeForm("ROBOTOMY REQUEST", "target");
		intern.makeForm("shrubbery", "target");
		intern.makeForm("president pardon", "target");

		std::cout << "\n=== Test 11: Case sensitivity ===" << std::endl;
		AForm* case_test = intern.makeForm("Robotomy request", "target");
		std::cout << "Case-sensitive test (should fail): " << (case_test ? "Created" : "Failed") << std::endl;

		std::cout << "\n=== Test 12: Execute unsigned form ===" << std::endl;
		AForm* unsigned_form = intern.makeForm("Presidential Pardon", "TestTarget");
		std::cout << "Form created but not signed, trying to execute:" << std::endl;
		boss.executeForm(*unsigned_form);

		std::cout << "\n=== Test 13: Copy intern and test functionality ===" << std::endl;
		Intern intern2;
		AForm* copy_test = intern2.makeForm("Robotomy Request", "Copy");
		std::cout << "Intern copy created form successfully" << std::endl;
		boss.signForm(*copy_test);
		boss.executeForm(*copy_test);

		std::cout << "\n=== Test 14: Clean up dynamically allocated forms ===" << std::endl;
		delete form1;
		delete form2;
		delete form3;
		delete robotomy;
		delete pardon;
		delete shrubbery;
		delete unsigned_form;
		delete copy_test;
		std::cout << "All forms deleted successfully" << std::endl;

		std::cout << "\n=== Test 15: Lowest grade bureaucrat with low-grade form ===" << std::endl;
		AForm* easy_form = intern.makeForm("Presidential Pardon", "EasyTarget");
		boss.signForm(*easy_form);
		lowest.executeForm(*easy_form);
		delete easy_form;

		return 0;
	}
}
// int main() {
// 	try {
// 		Bureaucrat bob("Bob", 2);
// 		std::cout << bob;
// 		bob.incrementGrade();
// 		std::cout << bob;
// 		bob.incrementGrade(); // exception
// 		std::cout << bob; // stops here
// 		bob.decrementGrade();
// 		std::cout << bob;
// 	} catch (const std::exception& e) {
// 		std::cerr << "Exception: " << e.what() << std::endl;
// 	}

// 	try {
// 		Bureaucrat alice("Alice", 149);
// 		std::cout << alice;
// 		alice.decrementGrade();
// 		std::cout << alice;
// 		alice.decrementGrade(); // exception
// 		std::cout << alice; // stops here
// 		alice.incrementGrade();
// 		std::cout << alice;
// 	} catch (const std::exception& e) {
// 		std::cerr << "Exception: " << e.what() << std::endl;
// 	}

// 	// AForm tests
// 	std::cout << "\n=== AForm Tests ===" << std::endl;
// 	Bureaucrat high("HighRank", 2);
// 	Bureaucrat lowRank("LowRank", 150);
// 	try {
// 		AForm *taxForm = new ShrubberyCreationForm("whatever");
// 		std::cout << *taxForm;
// 		std::cout << "AForm signed status: " << taxForm->getSignedStatus() << std::endl;
// 		std::cout << "Sign permission level: " << taxForm->getSignPermission() << std::endl;
// 		std::cout << "Exec permission level: " << taxForm->getExecPermission() << std::endl;
		
// 		Bureaucrat wow("john causes leaks?", 170); // no
		
// 		std::cout << "\nTrying to sign with grade " << high.getGrade() << " (need " << taxForm->getSignPermission() << ")..." << std::endl;
// 		lowRank.signForm(*taxForm);
// 		delete taxForm;
// 	} catch (const std::exception& e) {
// 		std::cerr << "Exception: " << e.what() << std::endl;
// 	}

// 	try {
// 		AForm *restrictedForm = new PresidentialPardonForm("A_Restricted_Form");
// 		std::cout << "\nTrying to sign with grade " << lowRank.getGrade() << " (need " << restrictedForm->getSignPermission() << ")..." << std::endl;
// 		lowRank.signForm(*restrictedForm);
// 		std::cout << "\nTrying to sign with grade " << high.getGrade() << " (need " << restrictedForm->getSignPermission() << ")..." << std::endl;
// 		high.signForm(*restrictedForm); // works because AForm throws an exeption not Bureaucrat
// 		delete restrictedForm;
// 	} catch (const std::exception& e) {
// 		std::cerr << "Exception: " << e.what() << std::endl;
// 	}

// 	return 0;
// }