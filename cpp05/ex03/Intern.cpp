#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstddef>

Intern::Intern()
{
	std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern& other)
{
	(void)other;
	std::cout << "Intern copy constructor called" << std::endl;

}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	std::cout << "Intern copy assignment called" << std::endl;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

static AForm* createShrubberyCreationForm(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomyRequestForm(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

static AForm* createPresidentialPardonForm(const std::string& target)
{
	return new PresidentialPardonForm(target);
}


struct FormEntry
{
	std::string name;
	AForm* (*create)(const std::string& target);
};

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
	static const FormEntry table[] = {
		{ "shrubbery creation",  &createShrubberyCreationForm  },
		{ "robotomy request",    &createRobotomyRequestForm    },
		{ "presidential pardon", &createPresidentialPardonForm }
	};
	static const std::size_t tableSize = sizeof(table) / sizeof(table[0]);

	for (std::size_t i = 0; i < tableSize; ++i)
	{
		if (table[i].name == name)
		{
			AForm* form = table[i].create(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return form;
		}
	}

	std::cerr << "Error: form \"" << name << "\" doesn't exist." << std::endl;
	return NULL;
}
