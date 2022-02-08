#include "includes/Intern.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/PresidentialPardonForm.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern::~Intern(void) {}

Intern &Intern::operator=(const Intern &)
{
	return *this;
}

Form *Intern::makeRobotomyRequestForm(const std::string&target) const
{
	return new RobotomyRequestForm(target);
}

Form *Intern::makePresidentialPardonForm(const std::string &target) const
{
	return new PresidentialPardonForm(target);
}

Form *Intern::makeShrubberyCreationForm(const std::string &target) const
{
	return new ShrubberyCreationForm(target);
}

Form *Intern::makeForm(const std::string &formName, const std::string &target) const
{
	std::string formNameList[] = {
		"robotomy request",
		"presidential pardon",
		"shrubbery creation"
	};
	Form *(Intern::*makeForms[3])(const std::string &) const = {
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm,
		&Intern::makeShrubberyCreationForm,
	};

	for (int i = 0; i < 3; i++)
	{
		if (formNameList[i] == formName)
		{
			std::cout << "Intern creates " << formName << " form" << std::endl;
			return (this->*makeForms[i])(target);
		}
	}
	std::cerr << "No relevant form name : " << formName << std::endl;
	return NULL;
}
