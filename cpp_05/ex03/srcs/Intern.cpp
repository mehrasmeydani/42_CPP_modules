#include "../header/Intern.hpp"
#include "../header/ShrubberyCreationForm.hpp"
#include "../header/RobotomyRequestForm.hpp"
#include "../header/PresidentialPardonForm.hpp"
#include <iostream>

AForm *Intern::makeForm(const std::string formName, const std::string target) {
	std::string forms[3] = {
		"Shrubbery Creation",
		"Robotomy Request",
		"Presidential Pardon"};
	AForm* (Intern::*formFunction[3])(const std::string) = {
		&Intern::makeShrubberyCreationForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm};
	for (int i = 0; i < 3; i++)
		if (forms[i] == formName)
			return (std::cout << "Intern creates " << formName << std::endl, (this->*formFunction[i])(target));
	std::cerr << "This intern could not find the requested form \"" << formName << "\" and now has to work overtime and it's your fault\n";
	return NULL;
}

const char* Intern::WrongFromException::what(void) const throw() {
	return "Wrong Form Requested";
}

AForm* Intern::makeShrubberyCreationForm(const std::string target) {
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeRobotomyRequestForm(const std::string target) {
	return (new RobotomyRequestForm(target));
}

AForm* Intern::makePresidentialPardonForm(const std::string target) {
	return (new PresidentialPardonForm(target));
}

Intern::Intern(void) {}

Intern::Intern(const Intern& in) {
	(void)in;
}

Intern &Intern::operator=(const Intern& in) {
	(void)in;
	return (*this);
}

Intern::~Intern(void) {}

