#include "../header/RobotomyRequestForm.hpp"
#include <cstdlib>

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (getSignedStatus() != 1)
		throw AForm::FormNotSigned();
	if (executor.getGrade() > getExecPermission())
		throw AForm::GradeTooLowException();
	if (std::rand() % 2)
		std::cout << "I'll inform you that "<< getTarget() <<" has been robotomized\n";
	else
		std::cout << "I'll inform you that "<< getTarget() <<" has NOT been robotomized\n";
	std::cout << "whatever that means\n";
}

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45, "home") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("Robotomy", 72, 43, target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& in) : AForm(in) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& in) {
	setSignedStatus(in.getSignedStatus());
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

