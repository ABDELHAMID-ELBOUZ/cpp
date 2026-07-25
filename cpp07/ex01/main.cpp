#include <iostream>
#include <string>
#include <cctype>
#include "iter.hpp"

void printInt(int const& n)
{
    std::cout << n << " ";
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    iter(arr1, 5, printInt);
    std::cout << std::endl;

    return 0;
}