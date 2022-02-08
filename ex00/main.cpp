#include "Bureaucrat.hpp"

# define SET_COLOR "\033[36m"
# define RESET_COLOR "\033[m"

void	printTestName(std::string testName)
{
	std::cout << SET_COLOR "\n/*** Test Bureaucrat " << testName <<\
				" ***/" RESET_COLOR << std::endl;
}

void	printTestInfo(std::string name, int grade, std::string append = "")
{
	std::cout << SET_COLOR "// Bureaucrat(name=" << name <<\
				 ", grade=" << std::to_string(grade) <<\
				 ")" << append <<\
				 RESET_COLOR << std::endl;
}

void	testDecrement(int grade)
{
	std::string		name = "Cathy";

	printTestInfo(name, grade, ".decrementGrage()");

	try
	{
		Bureaucrat b(name, grade);
		std::cout << "before: ";
		std::cout << b << std::endl;

		std::cout << "after : ";
		b.decrementGrade();
		std::cout << b << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	testIncrement(int grade)
{
	std::string		name = "Jhon";

	printTestInfo(name, grade, ".incrementGrage()");

	try
	{
		Bureaucrat b(name, grade);
		std::cout << "before: ";
		std::cout << b << std::endl;

		std::cout << "after : ";
		b.incrementGrade();
		std::cout << b << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	testConstructor(int grade)
{
	std::string		name = "Sum";

	printTestInfo(name, grade);

	try
	{
		Bureaucrat b(name, grade);
		std::cout << b << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int		main()
{
	printTestName("Constructor");
	testConstructor(1);
	testConstructor(2);
	testConstructor(42);
	testConstructor(150);
	testConstructor(151);

	printTestName("Increment");
	testIncrement(-1);
	testIncrement(0);
	testIncrement(1);
	testIncrement(2);
	testIncrement(42);
	testIncrement(150);
	testIncrement(151);

	printTestName("Decrement");
	testDecrement(-1);
	testDecrement(0);
	testDecrement(1);
	testDecrement(2);
	testDecrement(42);
	testDecrement(150);
	testDecrement(151);
}
