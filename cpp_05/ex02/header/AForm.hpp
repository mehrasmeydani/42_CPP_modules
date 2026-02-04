#pragma once

#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class AForm {
	private:
		const std::string name;
		bool Signed;
		const int signPermission;
		const int execPermission;
	public:
		bool getSignedStatus(void) const;
		const std::string& getName(void) const;
		virtual void beSigned(const Bureaucrat& employee) = 0;
		int getSignPermission(void) const;
		int getExecPermission(void) const;

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what(void) const throw();
		};

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what(void) const throw();
		};

		AForm();
		AForm(const std::string& name, const int signPermission, const int execPermission);
		AForm(const AForm& in);
		AForm& operator=(const AForm& in);
		virtual ~AForm() = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& in);