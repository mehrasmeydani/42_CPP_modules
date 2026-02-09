#include "../header/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Shrubbery", 145, 137, "Normal") {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& in) : AForm(in) {
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& in) {
    setSignedStatus(in.getSignedStatus());
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
}