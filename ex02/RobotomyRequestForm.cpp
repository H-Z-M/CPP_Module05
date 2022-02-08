#include "includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: Form("RobotomyRequestForm", 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: Form(other) {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	Form::operator=(rhs);
	return *this;
}

void	RobotomyRequestForm::beExecuted(void) const
{
	std::cout << "*** rizzz ***" << std::endl;
	if (std::rand() % 2)
		std::cout << getTarget() << " : Successful robotization" << std::endl;
	else
		std::cout << getTarget() << " : Failure robotization" << std::endl;
}
