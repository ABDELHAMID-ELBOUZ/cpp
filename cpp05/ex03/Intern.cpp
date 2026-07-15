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

static AForm* makeShrubbery(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

static AForm* makeRobotomy(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

static AForm* makePardon(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

static AForm* (*makers[])(const std::string&) = {
    makeShrubbery,
    makeRobotomy,
    makePardon
};

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
    const char* names[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    for (int i = 0; i < 3; i++)
    {
        if (names[i] == name)
        {
            AForm* form = makers[i](target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }

    std::cout << "Error: form \"" << name << "\" doesn't exist." << std::endl;
    return NULL;
}