#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name)
	: name(name), grade(150) {}

Bureaucrat::Bureaucrat(const std::string name, int grade)
	: name(name)
{
	this->grade = this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: name(other.name), grade(other.grade) {}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	grade = rhs.getGrade();
	return *this;
}

int Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw GradeTooLowException("GradeTooLowException");
	if (grade < 1)
		throw GradeTooHighException("GradeTooHighException");
	return grade;
}

int Bureaucrat::getGrade(void) const
{
	return this->grade;
}

const std::string Bureaucrat::getName(void) const
{
	return this->name;
}

void Bureaucrat::incrementGrade(void)
{
	this->grade = setGrade(--this->grade);
}

void Bureaucrat::decrementGrade(void)
{
	this->grade = setGrade(++this->grade);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}

/* GradeTooHighException */
Bureaucrat::GradeTooHighException::GradeTooHighException(const char *message)
	: message(message) {}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return this->message;
}

/* GradeTooLowException */
Bureaucrat::GradeTooLowException::GradeTooLowException(const char *message)
	: message(message) {}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return this->message;
}
