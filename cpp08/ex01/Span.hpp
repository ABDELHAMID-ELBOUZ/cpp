#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <numeric>

class Span
{
	private:
		unsigned int _maxSize;
		std::vector<int> _data;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int n);

		template<typename InputIterator>
		void addRange(InputIterator begin, InputIterator end)
		{
			size_t count = std::distance(begin, end);
			if (count < 0)
				throw std::runtime_error("Invalid iterator range");
			if (_data.size() + static_cast<unsigned int>(count) > _maxSize)
				throw std::runtime_error("Span capacity exceeded");

			_data.insert(_data.end(), begin, end);
		}
		int shortestSpan() const;
		int longestSpan() const;
		unsigned int size() const;
		unsigned int maxSize() const;
};

#endif