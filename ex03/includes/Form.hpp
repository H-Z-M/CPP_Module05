#ifndef FORM_HPP
# define FORM_HPP

class Form;
# include "Bureaucrat.hpp"

class Form
{
	public :
		Form(const std::string name);
		Form(const std::string name, int gradeToSign, int gradeToExec, std::string target);
		Form(const Form &other);
		virtual ~Form(void);
		Form &operator=(const Form &rhs);

		std::string getName(void) const;
		bool getIsSinged(void) const;
		int getGradeToSign(void) const;
		int getGradeToExec(void) const;
		std::string getTarget(void) const;
		int setGrade(int grade);

		void beSigned(const Bureaucrat &b);
		void execute(Bureaucrat const &executor) const;

		virtual void beExecuted(void) const = 0;


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
		bool isSigned;
		const int gradeToSign;
		const int gradeToExec;
		const std::string target;
};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif
