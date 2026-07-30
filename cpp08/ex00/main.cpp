#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    try
	{
        std::vector<int>::iterator it = easyfind(v, 2);
        std::cout << "Found: " << *it << std::endl;
    }
	catch (std::exception& e)
	{
        std::cout << "Not found" << std::endl;
    }

    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);

    try
	{
        std::list<int>::iterator it = easyfind(lst, 99);
        std::cout << *it << std::endl;
    }
	catch (std::exception& e)
	{
        std::cout << "Not found in list" << std::endl;
    }

    return 0;
}