#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "Form.hpp"

/****************** FOR PRINT and FORMATTING ******************/

# define SET_COLOR "\033[36m"
# define RESET_COLOR "\033[m"

void	printTestName(std::string testName)
{
	std::cout << SET_COLOR "\n/*** Test " << testName <<\
				" ***/" RESET_COLOR << std::endl;
}

std::string	createFormString(std::string name, int gradeToSign, int gradeToExec, bool isSigned = false)
{
	std::string signStatus = (isSigned ? "true" : "false");

	return "Form(name=" + name + ", gradeToSign=" + std::to_string(gradeToSign) +\
								 ", gradeToExec=" + std::to_string(gradeToExec) +\
								 ", isSigned=" + signStatus +\
				")";
}

std::string	createBureaucratString(std::string name, int grade)
{
	return "Bureaucrat(name=" + name + ", grade=" + std::to_string(grade) + ")";
}

void	printFormTestInfo(std::string name, int gradeToSign, int gradeToExec, bool isSigned = false, std::string append = "")
{
	std::cout << SET_COLOR "// " << createFormString(name, gradeToSign, gradeToExec, isSigned) <<\
				 append << RESET_COLOR << std::endl;
}

void	printBureaucratTestInfo(std::string name, int grade, std::string append = "")
{
	std::cout << SET_COLOR "// " << createBureaucratString(name, grade) <<\
				 append << RESET_COLOR << std::endl;
}

/******************************** TESTS ********************************/

void	testFormConstructor(int gradeToSign, int gradeToExec)
{
	std::string		name = "RandomForm";
	printFormTestInfo(name, gradeToSign, gradeToExec);

	try
	{
		Form f(name, gradeToSign, gradeToExec);
		std::cout << f << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	testCopyConstructor(int gradeToSign, int gradeToExec, bool isSigned)
{
	std::string		name = "RandomForm";
	printFormTestInfo(name, gradeToSign, gradeToExec, isSigned, " [ all values will be the same ]");

	try
	{
		Form f(name, gradeToSign, gradeToExec);
		/* signing the form */
		if (isSigned) {
			f.beSigned(Bureaucrat("tmp", 1));
		}

		std::cout << "Original: ";
		std::cout << f << std::endl;

		/* call copy constructor */
		Form f_copy(f);
		std::cout << "Copied  : ";
		std::cout << f_copy << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	testAssignationOperator(int gradeToSign, int gradeToExec, bool isSigned)
{
	std::string		name = "RandomForm";
	printFormTestInfo(name, gradeToSign, gradeToExec, isSigned, " [ only sign status will be the same ]");

	try
	{
		Form f(name, gradeToSign, gradeToExec);
		/* signing form f */
		if (isSigned) {
			f.beSigned(Bureaucrat("tmp", 1));
		}
		Form g(name + '2', gradeToExec, gradeToSign);

		std::cout << "src before copy: " << f << std::endl;
		std::cout << "dst before copy: " << g << std::endl;

		/* call assignation operator overload */
		g = f;
		// std::cout << "src after copy : " << f << std::endl;
		std::cout << "dst after copy : " << g << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	testFormBeSigned(int bureaucreatGrade, int gradeToSign, int gradeToExec)
{
	std::string	b_name = "Dan";
	std::string	f_name = "SignMe";
	printFormTestInfo(f_name, gradeToSign, gradeToExec, false, ".beSigned(" + createBureaucratString(b_name, bureaucreatGrade) + ')');

	try
	{
		Bureaucrat	b(b_name, bureaucreatGrade);
		Form		f(f_name, gradeToSign, gradeToExec);
		std::cout << "Before: " << b << std::endl;
		std::cout << "Before: " << f << std::endl;
		std::cout << "After : ";
		f.beSigned(b);
		std::cout << f << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	testBureaucratSignForm(int bureaucreatGrade, int gradeToSign, int gradeToExec)
{
	std::string	b_name = "Juliet";
	std::string	f_name = "UnimportantForm";
	printBureaucratTestInfo(b_name, bureaucreatGrade, ".SignForm(" + createFormString(f_name, gradeToSign, gradeToExec) + ')');

	try
	{
		Bureaucrat	b(b_name, bureaucreatGrade);
		Form		f(f_name, gradeToSign, gradeToExec);
		std::cout << "Before: " << b << std::endl;
		std::cout << "Before: " << f << std::endl;
		std::cout << "After : ";
		f.beSigned(b);
		std::cout << f << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

}

int		main()
{
	printTestName("Form Constructor");
	testFormConstructor(1, 2);
	testFormConstructor(2, 2);
	testFormConstructor(42, 2);
	testFormConstructor(150, 2);
	testFormConstructor(151, 2);

	printTestName("Form Copy constructor");
	testCopyConstructor(1, 150, false);
	testCopyConstructor(42, 2, true);

	printTestName("Form Assignation Operator =");
	testAssignationOperator(1, 150, false);
	testAssignationOperator(50, 2, true);

	printTestName("Form beSigned()");
	testFormBeSigned(1, 12, 15);
	testFormBeSigned(150, 12, 15);
	testFormBeSigned(42, 42, 15);

	printTestName("Bureaucrat signForm()");
	testBureaucratSignForm(9, 10, 150);
	testBureaucratSignForm(9, 5, 150);
}
