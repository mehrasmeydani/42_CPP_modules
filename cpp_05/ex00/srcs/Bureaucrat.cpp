#include "../header/Bureaucrat.hpp"
#include <iostream>

const std::string&	Bureaucrat::getName(void) const {
	return this->name;
}

int	Bureaucrat::getGrade(void) const {
	return this->grade;
}

void	Bureaucrat::setGrade(int newGrade) {
	if (newGrade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (newGrade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = newGrade;
}

void	Bureaucrat::incrementGrade(void) {
	if (getGrade() == 1)
		throw Bureaucrat::GradeTooHighException();
	setGrade(getGrade() - 1);
}

void	Bureaucrat::decrementGrade(void) {
	if (getGrade() == 150)
		throw Bureaucrat::GradeTooLowException();
	setGrade(getGrade() + 1);
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw() {
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw() {
	return "Grade too low";
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade) {
	if (getGrade() > 150)
		throw Bureaucrat::GradeTooLowException();
	if (getGrade() < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat() : name("Random dude"), grade(150) {
}

Bureaucrat::Bureaucrat(const Bureaucrat& in) : name(in.getName()), grade(in.getGrade()) {
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& in) {
	this->setGrade(in.getGrade());
	return (*this);
}

Bureaucrat::~Bureaucrat() {
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat& in) {
	os << in.getName() << ", bureaucrat grade " << in.getGrade() << std::endl;
	return os;
}