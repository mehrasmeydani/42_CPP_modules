#pragma once

#include "AForm.hpp"
#include <exception>

class Intern {
	public:
		AForm* makeShrubberyCreationForm(const std::string target);
		AForm* makeRobotomyRequestForm(const std::string target);
		AForm* makePresidentialPardonForm(const std::string target);

		AForm* makeForm(const std::string formName, const std::string in);

		class	WrongFromException : public std::exception {
			virtual const char* what(void) const throw();
		};
		
		Intern(void);
		Intern(const Intern& in);
		Intern& operator=(const Intern& other);
		~Intern();
	

};


