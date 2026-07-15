#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	Intern someRandomIntern;
	Bureaucrat zaphod("Zaphod", 1);

	std::cout << "test 1" << std::endl;
	AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	AForm* scf = someRandomIntern.makeForm("shrubbery creation", "garden");
	AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Marvin");

	std::cout << "test 2" << std::endl;
	AForm* bad = someRandomIntern.makeForm("time travel request", "1985");
	std::cout << "bad pointer is NULL: " << (bad == NULL ? "yes" : "no") << std::endl;

	std::cout << "test 3" << std::endl;
	if (rrf)
	{
		zaphod.signForm(*rrf);
		zaphod.executeForm(*rrf);
	}
	if (scf)
	{
		zaphod.signForm(*scf);
		zaphod.executeForm(*scf);
	}
	if (ppf)
	{
		zaphod.signForm(*ppf);
		zaphod.executeForm(*ppf);
	}

	delete rrf;
	delete scf;
	delete ppf;
	delete bad;
	return 0;
}
