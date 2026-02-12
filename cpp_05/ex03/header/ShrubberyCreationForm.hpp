#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string in);
		ShrubberyCreationForm(const ShrubberyCreationForm& in);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& in);
		~ShrubberyCreationForm();
		void execute(Bureaucrat const & executor) const;
};
