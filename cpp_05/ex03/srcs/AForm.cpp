#include "../header/AForm.hpp"
#include <iostream>

void AForm::beSigned(const Bureaucrat& employee) {
	if (this->getSignedStatus() != 0)
		return ;
	if (employee.getGrade() > this->getSignPermission())
		throw AForm::GradeTooLowException();
	setSignedStatus(1);
}

int AForm::getExecPermission(void) const {
	return this->execPermission;
}


int AForm::getSignPermission(void) const {
	return this->signPermission;
}

const std::string& AForm::getName(void) const {
	return this->name;
}

bool AForm::getSignedStatus(void) const {
	return this->Signed;
}

void AForm::setSignedStatus(bool in) {
	this->Signed = in;
}

const std::string& AForm::getTarget(void) const {
	return this->target;
}

const char* AForm::GradeTooLowException::what(void) const throw() {
	return "Grade Too Low";
}

const char* AForm::GradeTooHighException::what(void) const throw() {
	return "Grade Too High";
}

const char* AForm::FormNotSigned::what(void) const throw(){
	return "Not signed";
}

AForm::AForm() : name("Random AForm"), Signed(0), signPermission(75), execPermission(20) , target("Random Target") {
}

AForm::AForm(const std::string& name, const int signPermission, const int execPermission, const std::string& target) : name(name), Signed(0), signPermission(signPermission), execPermission(execPermission), target(target) {
	if (getExecPermission() > 150 || getSignPermission() > 150)
		throw AForm::GradeTooLowException();
	if (getExecPermission() < 1 || getSignPermission() < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm& in) : name(in.getName()), Signed(in.getSignedStatus()), signPermission(in.getSignPermission()), execPermission(in.getExecPermission()), target(in.getTarget()) {
}

AForm& AForm::operator=(const AForm& in) {
	Signed = in.getSignedStatus();
	return *this;
}

std::ostream& operator<<(std::ostream& os, const AForm& in) {
	os << "AForm " << in.getName() << " needs an Sign grade of " << in.getSignPermission() << " and a Execution grade of " << in.getExecPermission() << " and has ";
	if (in.getSignedStatus() == 0)
		os << "NOT";
	os << " been Signed!" << std::endl;
	return os;
}

AForm::~AForm() {
}