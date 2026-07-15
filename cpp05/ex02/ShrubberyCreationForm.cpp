#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), target("Default Target")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), target(other.target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
	std::cout << "ShrubberyCreationForm copy assignment called" << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream file((target + "_shrubbery").c_str());
	if (!file.is_open())
    	throw std::runtime_error("Failed to open file for shrubbery creation");
	file << "      *\n"
	     << "     ***\n"
	     << "    *****\n"
	     << "   *******\n"
	     << "  *********\n"
	     << "      |\n";
	file.close();
}
