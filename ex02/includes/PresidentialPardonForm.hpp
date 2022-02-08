#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form
{
	public :
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		virtual ~PresidentialPardonForm(void);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

	private :
		virtual void beExecuted(void) const;
};

#endif
