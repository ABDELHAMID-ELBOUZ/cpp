#include "PmergeMe.hpp"
#include <algorithm>
#include <utility>

PmergeMe::PmergeMe()
{

}
PmergeMe::PmergeMe(const PmergeMe&)
{

}
PmergeMe& PmergeMe::operator=(const PmergeMe&)
{ 
	return *this; 
}
PmergeMe::~PmergeMe()
{

}

static void mergeInsertVector(std::vector<int>& v)
{
    if (v.size() <= 1) return;

    std::vector<std::pair<int, int> > pairs;
    size_t i = 0;
    for (; i + 1 < v.size(); i += 2)
	{
        if (v[i] < v[i + 1])
            pairs.push_back(std::make_pair(v[i + 1], v[i]));
        else
            pairs.push_back(std::make_pair(v[i], v[i + 1]));
    }

    bool hasOdd = false;
    int odd = 0;
    if (i < v.size())
	{
        hasOdd = true;
        odd = v[i];
    }

    std::vector<int> mainVec;
    for (size_t j = 0; j < pairs.size(); ++j)
        mainVec.push_back(pairs[j].first);
    mergeInsertVector(mainVec);

    std::sort(pairs.begin(), pairs.end());

    std::vector<int> main;
    std::vector<int> pend;
    for (size_t j = 0; j < pairs.size(); ++j)
	{
        main.push_back(pairs[j].first);
        pend.push_back(pairs[j].second);
    }

    std::vector<int> order;
    if (!pend.empty())
	{
        order.push_back(0);
        int prev = 1;
        int a = 1, b = 3;
        while (prev < (int)pend.size())
		{
            int J = b;
            int start = std::min(J, (int)pend.size());
            for (int k = start; k > prev; --k)
                order.push_back(k - 1);
            prev = J;
            int next = b + 2 * a;
            a = b;
            b = next;
        }
    }

    for (size_t k = 0; k < order.size(); ++k)
	{
        int idx = order[k];
        int val = pend[idx];
        std::vector<int>::iterator it = std::lower_bound(main.begin(), main.end(), val);
        main.insert(it, val);
    }

    if (hasOdd)
	{
        std::vector<int>::iterator it = std::lower_bound(main.begin(), main.end(), odd);
        main.insert(it, odd);
    }

    v = main;
}

static void mergeInsertDeque(std::deque<int>& d)
{
    if (d.size() <= 1) return;

    std::deque<std::pair<int, int> > pairs;
    size_t i = 0;
    for (; i + 1 < d.size(); i += 2)
	{
        if (d[i] < d[i + 1])
            pairs.push_back(std::make_pair(d[i + 1], d[i]));
        else
            pairs.push_back(std::make_pair(d[i], d[i + 1]));
    }

    bool hasOdd = false;
    int odd = 0;
    if (i < d.size())
	{
        hasOdd = true;
        odd = d[i];
    }

    std::deque<int> mainDeq;
    for (size_t j = 0; j < pairs.size(); ++j)
        mainDeq.push_back(pairs[j].first);
    mergeInsertDeque(mainDeq);

    std::sort(pairs.begin(), pairs.end());

    std::deque<int> main;
    std::deque<int> pend;
    for (size_t j = 0; j < pairs.size(); ++j)
	{
        main.push_back(pairs[j].first);
        pend.push_back(pairs[j].second);
    }

    std::deque<int> order;
    if (!pend.empty())
	{
        order.push_back(0);
        int prev = 1;
        int a = 1, b = 3;
        while (prev < (int)pend.size())
		{
            int J = b;
            int start = std::min(J, (int)pend.size());
            for (int k = start; k > prev; --k)
                order.push_back(k - 1);
            prev = J;
            int next = b + 2 * a;
            a = b;
            b = next;
        }
    }

    for (size_t k = 0; k < order.size(); ++k)
	{
        int idx = order[k];
        int val = pend[idx];
        std::deque<int>::iterator it = std::lower_bound(main.begin(), main.end(), val);
        main.insert(it, val);
    }

    if (hasOdd)
	{
        std::deque<int>::iterator it = std::lower_bound(main.begin(), main.end(), odd);
        main.insert(it, odd);
    }

    d = main;
}

void PmergeMe::sortVector(std::vector<int>& v)
{
    mergeInsertVector(v);
}

void PmergeMe::sortDeque(std::deque<int>& d)
{
    mergeInsertDeque(d);
}