#include "includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: Form("PresidentialPardonForm", 25, 5, target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: Form(other) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	Form::operator=(rhs);
	return *this;
}

void	PresidentialPardonForm::beExecuted(void) const
{
	std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
