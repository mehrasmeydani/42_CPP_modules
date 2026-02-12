#pragma once

#include <string>
#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

class AForm {
	private:
		const std::string name;
		bool Signed;
		const int signPermission;
		const int execPermission;
		const std::string target;
	public:
		void setSignedStatus(bool in);

		void beSigned(const Bureaucrat& employee);
		virtual void execute(Bureaucrat const & executor) const = 0;

		bool getSignedStatus(void) const;
		const std::string& getName(void) const;
		const std::string& getTarget(void) const;
		int getSignPermission(void) const;
		int getExecPermission(void) const;

		class FormNotSigned : public std::exception {
			public:
				virtual const char* what(void) const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what(void) const throw();
		};

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what(void) const throw();
		};

		AForm();
		AForm(const std::string& name, const int signPermission, const int execPermission, const std::string& target);
		AForm(const AForm& in);
		AForm& operator=(const AForm& in);
		virtual ~AForm() = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& in);