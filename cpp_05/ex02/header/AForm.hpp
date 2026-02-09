#pragma once

#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class AForm {
	private:
		const std::string target;
		bool Signed;
		const int signPermission;
		const int execPermission;
		const std::string name;
	public:
		bool getSignedStatus(void) const;
		void setSignedStatus(bool in);
		const std::string& getName(void) const;
		const std::string& getTarget(void) const;
		void beSigned(const Bureaucrat& employee);
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
		AForm(const std::string& name, const int signPermission, const int execPermission, const std::string& target);
		AForm(const AForm& in);
		AForm& operator=(const AForm& in);
		virtual ~AForm() = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& in);