#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string in);
		RobotomyRequestForm(const RobotomyRequestForm& in);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& in);
		~RobotomyRequestForm();
		void execute(Bureaucrat const & executor) const;
};