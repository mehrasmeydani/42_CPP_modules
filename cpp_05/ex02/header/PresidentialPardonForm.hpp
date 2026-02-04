#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& in);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& in);
		~PresidentialPardonForm();
		void	beSigned(const Bureaucrat& in);
};