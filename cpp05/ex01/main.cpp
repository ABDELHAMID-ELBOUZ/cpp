#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "test 1" << std::endl;
    try
	{
        Form invalidForm("invalidForm", 0, 50);
    }
	catch (std::exception& e)
	{
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    try
	{
        Form invalidForm2("invalidForm 2", 151, 50);
    }
	catch (std::exception& e)
	{
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    std::cout << "test 2" << std::endl;
    try
	{
        Bureaucrat Bureaucrat("Bureaucrat", 10);
        Form form("form", 20, 45);

        std::cout << form << std::endl;
        Bureaucrat.signForm(form);
        std::cout << form << std::endl;
    }
	catch (std::exception& e)
	{
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "test 3" << std::endl;
    try
    {
        Bureaucrat Bureaucrat("Bureaucrat", 140);
        Form form("form", 5, 5);

        std::cout << form << std::endl;
        Bureaucrat.signForm(form);
        std::cout << form << std::endl;
    }
	catch (std::exception& e)
	{
        std::cout << "Unexpected crash exception: " << e.what() << std::endl;
    }

    return 0;
}