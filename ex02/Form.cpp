#include "includes/Form.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExec, std::string target)
	: name(name), isSigned(false),
		gradeToSign(setGrade(gradeToSign)), gradeToExec(setGrade(gradeToExec)),
		target(target) {}

Form::Form(const Form &other)
	: name(other.name), isSigned(other.isSigned),
		gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec),
		target(other.target)
{
	*this = other;
}

Form::~Form(void) {}

Form &Form::operator=(const Form &rhs)
{
	this->isSigned = rhs.isSigned;
	return *this;
}

std::string Form::getName(void) const
{
	return this->name;
}
bool Form::getIsSinged(void) const
{
	return this->isSigned;
}
int Form::getGradeToSign(void) const
{
	return this->gradeToSign;
}
int Form::getGradeToExec(void) const
{
	return this->gradeToExec;
}

std::string Form::getTarget(void) const
{
	return this->target;
}

int Form::setGrade(int grade)
{
	if (grade > 150)
		throw GradeTooLowException("GradeTooLowException");
	if (grade < 1)
		throw GradeTooHighException("GradeTooHighException");
	return grade;
}

void Form::beSigned(const Bureaucrat &b)
{
	if (this->gradeToSign < b.getGrade())
		throw GradeTooLowException("GradeTooLowException");
	this->isSigned = true;
}

void Form::execute(Bureaucrat const &executor) const
{
	if (!this->isSigned)
        throw std::runtime_error("It hasn't been signed yet");
	if (this->gradeToExec < executor.getGrade())
		throw GradeTooLowException("GradeTooLowException");
	beExecuted();
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
	os << f.getName()
		<< ": [grade to sign] " << f.getGradeToSign()
		<< ", [grade to execute] " << f.getGradeToExec()
		<< ", [signed] " << std::boolalpha << f.getIsSinged()
		<< ", [target] " << f.getTarget();
	return os;
}

/* GradeTooHighException */
Form::GradeTooHighException::GradeTooHighException(const char *message)
	: message(message) {}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return this->message;
}

/* GradeTooLowException */
Form::GradeTooLowException::GradeTooLowException(const char *message)
	: message(message) {}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return this->message;
}
