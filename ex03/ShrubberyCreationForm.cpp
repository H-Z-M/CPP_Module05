#include "includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: Form("ShrubberyCreationForm", 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: Form(other) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	Form::operator=(rhs);
	return *this;
}

void	ShrubberyCreationForm::beExecuted(void) const
{
	std::ofstream	ofs(getTarget() + "_shrubbery");

	if (ofs.fail())
		std::exit(EXIT_FAILURE);
	ofs << ". \n\
|-- Bureaucrat.cpp \n\
|-- Form.cpp \n\
|-- Makefile \n\
|-- PresidentialPardonForm.cpp \n\
|-- RobotomyRequestForm.cpp \n\
|-- ShrubberyCreationForm.cpp \n\
|-- main.cpp \n\
`-- includes \n\
    |-- Bureaucrat.hpp \n\
    |-- Form.hpp \n\
    |-- PresidentialPardonForm.hpp \n\
    |-- RobotomyRequestForm.hpp \n\
    `-- ShrubberyCreationForm.hpp \n";
}
