#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string in);
		PresidentialPardonForm(const PresidentialPardonForm& in);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& in);
		~PresidentialPardonForm();
		void execute(Bureaucrat const & executor) const;
};