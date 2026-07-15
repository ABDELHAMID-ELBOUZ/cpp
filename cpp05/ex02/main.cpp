#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	std::cout << "test 1" << std::endl;
	{
		Bureaucrat Bureaucrat("Bureaucrat", 1);
		ShrubberyCreationForm ShrubberyCreationForm("ShrubberyCreationForm");

		Bureaucrat.signForm(ShrubberyCreationForm);
		Bureaucrat.executeForm(ShrubberyCreationForm);
	}

	std::cout << "test 2" << std::endl;
	{
		Bureaucrat Bureaucrat("Bureaucrat", 72);
		RobotomyRequestForm RobotomyRequestForm("RobotomyRequestForm");

		Bureaucrat.signForm(RobotomyRequestForm);    
		Bureaucrat.executeForm(RobotomyRequestForm); 
	}

	std::cout << "test 3" << std::endl;
	{
		Bureaucrat Bureaucrat("Bureaucrat", 140);
		PresidentialPardonForm PresidentialPardonForm("PresidentialPardonForm");

		Bureaucrat.signForm(PresidentialPardonForm);    
		Bureaucrat.executeForm(PresidentialPardonForm); 
	}

	std::cout << "test 4" << std::endl;
	{
		Bureaucrat signer("Leela", 25);
		Bureaucrat executor("Zapp", 10);
		PresidentialPardonForm PresidentialPardonForm("PresidentialPardonForm");

		signer.signForm(PresidentialPardonForm);     
		executor.executeForm(PresidentialPardonForm);
	}

	std::cout << "test 5" << std::endl;
	{
		Bureaucrat zaphod("Zaphod", 1);
		PresidentialPardonForm PresidentialPardonForm("PresidentialPardonForm");

		zaphod.signForm(PresidentialPardonForm);
		zaphod.executeForm(PresidentialPardonForm);
	}

	return 0;
}
