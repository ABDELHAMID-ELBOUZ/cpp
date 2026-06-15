#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "--- Test 1: Form Creation Exceptions ---" << std::endl;
    try {
        Form invalidForm("Tax Fraud", 0, 50);
    } catch (std::exception& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    try {
        Form invalidForm2("Tax Fraud 2", 151, 50);
    } catch (std::exception& e) {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 2: Successful Signing ---" << std::endl;
    try {
        Bureaucrat boss("Hermes Conrad", 10);
        Form simpleForm("Permit A38", 20, 45);

        std::cout << simpleForm << std::endl;
        boss.signForm(simpleForm);
        std::cout << simpleForm << std::endl;
    } catch (std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 3: Failed Signing ---" << std::endl;
    try {
        Bureaucrat intern("Philip J. Fry", 140);
        Form topSecretForm("Classified Document", 5, 5);

        std::cout << topSecretForm << std::endl;
        intern.signForm(topSecretForm);
        std::cout << topSecretForm << std::endl;
    } catch (std::exception& e) {
        std::cout << "Unexpected crash exception: " << e.what() << std::endl;
    }

    return 0;
}