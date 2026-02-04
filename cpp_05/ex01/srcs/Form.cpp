#include "../header/Form.hpp"
#include <iostream>

void Form::beSigned(const Bureaucrat& employee) {
	if (this->getSignedStatus() != 0)
		return ;
	if (employee.getGrade() > this->getSignPermission())
		throw Form::GradeTooLowException();
	this->Signed = 1;
}

int Form::getExecPermission(void) const {
	return this->execPermission;
}


int Form::getSignPermission(void) const {
	return this->signPermission;
}

const std::string& Form::getName(void) const {
	return this->name;
}

bool Form::getSignedStatus(void) const {
	return this->Signed;
}

const char* Form::GradeTooLowException::what(void) const throw() {
	return "Grade Too Low";
}

const char* Form::GradeTooHighException::what(void) const throw() {
	return "Grade Too High";
}

Form::Form() : name("Random Form"), Signed(0), signPermission(75), execPermission(20) {
}

Form::Form(const std::string& name, const int signPermission, const int execPermission) : name(name), Signed(0), signPermission(signPermission), execPermission(execPermission) {
	if (getExecPermission() > 150 || getSignPermission() > 150)
		throw Form::GradeTooLowException();
	if (getExecPermission() < 1 || getSignPermission() < 1)
		throw Form::GradeTooHighException();
}

Form::Form(const Form& in) : name(in.getName()), Signed(in.getSignedStatus()), signPermission(in.getSignPermission()), execPermission(in.getExecPermission()) {
}

Form& Form::operator=(const Form& in) {
	Signed = in.getSignedStatus();
	return *this;
}

Form::~Form() {
}

std::ostream& operator<<(std::ostream& os, const Form& in) {
	os << "Form " << in.getName() << " needs an Sign grade of " << in.getSignPermission() << " and a Execution grade of " << in.getExecPermission() << " and has ";
	if (in.getSignedStatus() == 0)
		os << "NOT";
	os << " been Signed!" << std::endl;
	return os;
}