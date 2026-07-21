#include "functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base* generate(void)
{
    static bool seeded = false;
    if (!seeded)
	{
        std::srand(std::time(NULL));
        seeded = true;
    }
    switch (std::rand() % 3)
	{
        case 0:
			return new A();
        case 1:
			return new B();
        case 2:
			return new C();
    }
    return NULL;
}

void identify(Base* p)
{
    if (p == NULL)
        return;
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "C" << std::endl;
}

void identify(Base& p)
{
    try
	{
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
	catch (...)
	{

	}
    try
	{
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
	catch (...)
	{

	}
    try 
	{
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
	catch (...)
	{

	}
}
