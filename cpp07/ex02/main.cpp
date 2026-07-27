#include <iostream>
#include "Array.hpp"

int main()
{
    Array<int> a(3);
    a[0] = 10;
    a[1] = 20;
    a[2] = 30;

    Array<int> b(a);
    a[0] = 99;

    std::cout << "a[0] = " << a[0] << "\nb[0] = " << b[0] << std::endl;

    try
	{
        a[1] = 0;
    }
	catch (std::exception&)
	{
        std::cout << "exception caught" << std::endl;
    }

    return 0;
}