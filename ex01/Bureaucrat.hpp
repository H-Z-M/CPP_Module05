#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include <string>

class Bureaucrat;
# include "Form.hpp"

class Bureaucrat
{
	public :
		Bureaucrat(const std::string name);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat(void);
		Bureaucrat &operator=(const Bureaucrat &rhs);

		int getGrade(void) const;
		int setGrade(int grade);
		const std::string getName(void) const;
		void incrementGrade(void);
		void decrementGrade(void);

		void signForm(Form &f);


		class GradeTooHighException : public std::exception
		{
			public :
				GradeTooHighException(const char *message);
				virtual const char *what(void) const throw();

			private :
				const char *message;
		};
		class GradeTooLowException : public std::exception
		{
			public :
				GradeTooLowException(const char *message);
				virtual const char *what(void) const throw();

			private :
				const char *message;
		};


	private :
		const std::string name;
		int grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif
