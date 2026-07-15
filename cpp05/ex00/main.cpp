#include "Bureaucrat.hpp"

int main()
{
    std::cout << "test 1" << std::endl;
    try
    {
        Bureaucrat a("Bureaucrat", 1);
        std::cout << a << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Unexpected: " << e.what() << std::endl;
    }

    std::cout << "test 2" << std::endl;
    try
    {
        Bureaucrat bad("Bad Bureaucrat", 0);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "test 3" << std::endl;
    try
    {
        Bureaucrat bad("Bad Bureaucrat", 151);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "test 4" << std::endl;
    try
    {
        Bureaucrat top("Top Bureaucrat", 1);
        top.incrementGrade();
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "test 5" << std::endl;
    try
    {
        Bureaucrat bottom("Bottom Bureaucrat", 150);
        bottom.decrementGrade();
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "test 6" << std::endl;
    try
    {
        Bureaucrat B("Bureaucrat", 75);
        std::cout << "Before: " << B << std::endl;
        B.incrementGrade();
        std::cout << "After increment: " << B << std::endl;
        B.decrementGrade();
        std::cout << "After decrement: " << B << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Unexpected: " << e.what() << std::endl;
    }

    return 0;
}