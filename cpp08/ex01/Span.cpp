#include "Span.hpp"

Span::Span() : _maxSize(0)
{

}

Span::Span(unsigned int n) : _maxSize(n)
{

}

Span::Span(const Span& other) : _maxSize(other._maxSize), _data(other._data)
{

}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
	{
        _maxSize = other._maxSize;
        _data = other._data;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
    if (_data.size() >= _maxSize)
        throw std::runtime_error("Span is full");
    _data.push_back(n);
}


int Span::shortestSpan() const
{
    if (_data.size() < 2)
        throw std::runtime_error("Not enough elements to calculate span");

    std::vector<int> copy = _data;
    std::sort(copy.begin(), copy.end());

    std::vector<int> diffs(copy.size());
    std::adjacent_difference(copy.begin(), copy.end(), diffs.begin());

    return *std::min_element(diffs.begin() + 1, diffs.end());
}

int Span::longestSpan() const
{
    if (_data.size() < 2)
        throw std::runtime_error("Not enough elements to calculate span");

    std::vector<int>::const_iterator minIt = std::min_element(_data.begin(), _data.end());
    std::vector<int>::const_iterator maxIt = std::max_element(_data.begin(), _data.end());

    return *maxIt - *minIt;
}

unsigned int Span::size() const
{
    return _data.size();
}

unsigned int Span::maxSize() const
{
    return _maxSize;
}