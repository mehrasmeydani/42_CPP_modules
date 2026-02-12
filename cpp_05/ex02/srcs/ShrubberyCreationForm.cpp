#include "../header/ShrubberyCreationForm.hpp"
#include <fstream>

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (getSignedStatus() != 1)
		throw AForm::FormNotSigned();
	if (executor.getGrade() > getExecPermission())
		throw AForm::GradeTooLowException();
	try {
		std::ofstream outfile((getTarget() + "_shrubbery").c_str());
		outfile << "ASCII trees\n";
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137, "Home") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("Shrubbery", 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& in) : AForm(in) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& in) {
	setSignedStatus(in.getSignedStatus());
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}