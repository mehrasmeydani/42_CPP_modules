#include "../header/PresidentialPardonForm.hpp"

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (getSignedStatus() != 1)
		throw AForm::FormNotSigned();
	if (executor.getGrade() > getExecPermission())
		throw AForm::GradeTooLowException();
	std::cout << "I am here to inform you " << getTarget() << " has been pardoned!\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("President", 25, 5, target) {
}

PresidentialPardonForm::PresidentialPardonForm() : AForm("President", 25, 5, "Home") {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& in) : AForm(in) {
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& in) {
	setSignedStatus(in.getSignedStatus());
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
}