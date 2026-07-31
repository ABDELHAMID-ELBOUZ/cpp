#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    Span big(10000);
    std::srand(std::time(NULL));

    std::vector<int> bulk;
    for (int i = 0; i < 10000; ++i)
        bulk.push_back(std::rand());

    big.addRange(bulk.begin(), bulk.end());
    std::cout << big.shortestSpan() << std::endl;
    std::cout << big.longestSpan() << std::endl;

    Span empty(5);
    try
	{
		empty.shortestSpan();
	} catch (...)
	{
		std::cout << "Empty OK\n";
	}

    Span one(5);
    one.addNumber(42);
    try
	{
		one.longestSpan();
	}
	catch (...)
	{
		std::cout << "One element OK\n";
	}

    Span full(3);
    full.addNumber(1);
    full.addNumber(2);
    full.addNumber(3);
    try
	{
		full.addNumber(4);
	}
	catch (...)
	{
		std::cout << "Full OK\n";
	}

    return 0;
}