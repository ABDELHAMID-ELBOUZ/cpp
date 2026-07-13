#include "Bureaucrat.hpp"

int main()
{
    std::cout << "=== Test 1: Valid construction ===" << std::endl;
    try {
        Bureaucrat a("Alice", 1);
        Bureaucrat b("Bob", 75);
        Bureaucrat c("Charlie", 150);
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << c << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Unexpected: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: Grade too high (0) ===" << std::endl;
    try {
        Bureaucrat bad("Bad", 0);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: Grade too low (151) ===" << std::endl;
    try {
        Bureaucrat bad("Bad", 151);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Increment boundary ===" << std::endl;
    try {
        Bureaucrat top("Top", 1);
        top.incrementGrade();  // Should throw
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 5: Decrement boundary ===" << std::endl;
    try {
        Bureaucrat bottom("Bottom", 150);
        bottom.decrementGrade();  // Should throw
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 6: Normal increment/decrement ===" << std::endl;
    try {
        Bureaucrat mid("Mid", 75);
        std::cout << "Before: " << mid << std::endl;
        mid.incrementGrade();
        std::cout << "After increment: " << mid << std::endl;
        mid.decrementGrade();
        std::cout << "After decrement: " << mid << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Unexpected: " << e.what() << std::endl;
    }

    return 0;
}