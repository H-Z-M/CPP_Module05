#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"

class RobotomyRequestForm : public Form
{
	public :
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		virtual ~RobotomyRequestForm(void);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

	private :
		virtual void beExecuted(void) const;
};

#endif
