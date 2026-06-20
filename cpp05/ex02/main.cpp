#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	std::cout << "--- Test 1: sign + execute succeed ---" << std::endl;
	{
		Bureaucrat boss("Hermes", 1);
		ShrubberyCreationForm shrub("home");

		boss.signForm(shrub);
		boss.executeForm(shrub);
	}

	std::cout << "\n--- Test 2: can sign, cannot execute ---" << std::endl;
	{
		Bureaucrat midLevel("Fry", 72);
		RobotomyRequestForm robo("Bender");

		midLevel.signForm(robo);    
		midLevel.executeForm(robo); 
	}

	std::cout << "\n--- Test 3: cannot sign at all ---" << std::endl;
	{
		Bureaucrat hmad("hmad", 140);
		PresidentialPardonForm pardon("Bender");

		hmad.signForm(pardon);    
		hmad.executeForm(pardon); 
	}

	std::cout << "\n--- Test 4: signed but executed by unauthorized grade ---" << std::endl;
	{
		Bureaucrat signer("Leela", 25);
		Bureaucrat executor("Zapp", 10);
		PresidentialPardonForm pardon("Nibbler");

		signer.signForm(pardon);     
		executor.executeForm(pardon);
	}

	std::cout << "\n--- Test 5: fully authorized executor ---" << std::endl;
	{
		Bureaucrat zaphod("Zaphod", 1);
		PresidentialPardonForm pardon("Marvin");

		zaphod.signForm(pardon);
		zaphod.executeForm(pardon);
	}

	return 0;
}
