#include "PmergeMe.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <sys/time.h>
#include <algorithm>
#include <vector>
#include <deque>
#include <iomanip>

long getTime()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000 + tv.tv_usec;
}

template <typename T>
void printSequence(const T& seq)
{
    if (seq.size() <= 10)
	{
        for (typename T::const_iterator it = seq.begin(); it != seq.end(); ++it)
            std::cout << *it << " ";
    } else
	{
        typename T::const_iterator it = seq.begin();
        for (int i = 0; i < 4; ++i, ++it)
            std::cout << *it << " ";
        std::cout << "[...]";
    }
    std::cout << std::endl;
}

int main(int argc, char** argv)
{
    if (argc < 2)
	{
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::deque<int> deq;

    for (int i = 1; i < argc; ++i)
	{
        std::string arg = argv[i];
        if (arg.empty())
		{
            std::cerr << "Error" << std::endl;
            return 1;
        }
        for (size_t j = 0; j < arg.size(); ++j)
		{
            if (!std::isdigit(arg[j]))
			{
                std::cerr << "Error" << std::endl;
                return 1;
            }
        }
        int val = std::atoi(arg.c_str());
        if (val < 0)
		{
            std::cerr << "Error" << std::endl;
            return 1;
        }
        vec.push_back(val);
        deq.push_back(val);
    }

    std::cout << "Before: ";
    printSequence(vec);

    long start = getTime();
    PmergeMe::sortVector(vec);
    long end = getTime();
    std::cout << "After: ";
    printSequence(vec);
    double vecTime = (end - start);
    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : " << std::fixed << std::setprecision(5)
              << vecTime << " us" << std::endl;

    start = getTime();
    PmergeMe::sortDeque(deq);
    end = getTime();
    double deqTime = (end - start);
    std::cout << "Time to process a range of " << deq.size()
              << " elements with std::deque : " << std::fixed << std::setprecision(5)
              << deqTime << " us" << std::endl;

    return 0;
}