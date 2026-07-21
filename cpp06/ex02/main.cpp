#include "functions.hpp"
#include <iostream>

int main()
{
    for (int i = 0; i < 6; i++)
	{
        Base* p = generate();
        std::cout << "Pointer: ";
        identify(p);
        std::cout << "Reference: ";
        identify(*p);
        delete p;
    }
    return 0;
}
