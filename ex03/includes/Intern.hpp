#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"

class Intern
{
	public :
		Intern(void);
		Intern(const Intern &other);
		~Intern(void);
		Intern &operator=(const Intern &rhs);

		Form *makeForm(const std::string &formName, const std::string &target) const;
		Form *makeShrubberyCreationForm(const std::string &target) const;
		Form *makeRobotomyRequestForm(const std::string &target) const;
		Form *makePresidentialPardonForm(const std::string &target) const;
};

#endif
