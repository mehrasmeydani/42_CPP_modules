#pragma once

#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Form {
	private:
		const std::string name;
		bool Signed;
		const int signPermission;
		const int execPermission;
	public:
		bool getSignedStatus(void) const;
		const std::string& getName(void) const;
		void beSigned(const Bureaucrat& employee);
		const int getSignPermission(void) const;
		const int getExecPermission(void) const;

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what(void) const throw();
		};

		Form();
		Form(const std::string& name, const int signPermission, const int execPermission);
		Form(const Form& in);
		Form &operator=(const Form& in);
		~Form();
};