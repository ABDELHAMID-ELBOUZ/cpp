#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));

	Intern someRandomIntern;
	Bureaucrat zaphod("Zaphod", 1);

	std::cout << "test 1" << std::endl;
	AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	AForm* scf = someRandomIntern.makeForm("shrubbery creation", "garden");
	AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Marvin");
	AForm* rrf1 = someRandomIntern.makeForm("robotomy request", "Bender1");
	AForm* scf1 = someRandomIntern.makeForm("shrubbery creation", "garden1");
	AForm* ppf1 = someRandomIntern.makeForm("presidential pardon", "Marvin1");

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
	if (rrf1)
	{
		zaphod.signForm(*rrf1);
		zaphod.executeForm(*rrf1);
	}
	if (scf1)
	{
		zaphod.signForm(*scf1);
		zaphod.executeForm(*scf1);
	}
	if (ppf1)
	{
		zaphod.signForm(*ppf1);
		zaphod.executeForm(*ppf1);
	}

	delete rrf;
	delete scf;
	delete ppf;
	delete rrf1;
	delete scf1;
	delete ppf1;
	delete bad;
	return 0;
}
