#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template<typename T>
class Array {
	private:
		T* _data;
		unsigned int _size;

	public:
		Array() : _data(NULL), _size(0) {}

		Array(unsigned int n) : _data(new T[n]()), _size(n) {}

		Array(Array const& other) : _data(new T[other._size]()), _size(other._size)
		{
			for (unsigned int i = 0; i < _size; ++i)
				_data[i] = other._data[i];
		}

		Array& operator=(Array const& other)
		{
			if (this != &other)
			{
				delete[] _data;
				_data = new T[other._size]();
				_size = other._size;
				for (unsigned int i = 0; i < _size; ++i)
					_data[i] = other._data[i];
			}
			return *this;
		}

		~Array()
		{
			delete[] _data;
		}

		T& operator[](unsigned int i)
		{
			if (i >= _size)
				throw std::exception();
			return _data[i];
		}

		T const& operator[](unsigned int i) const
		{
			if (i >= _size)
				throw std::exception();
			return _data[i];
		}

		unsigned int size() const
		{
			return _size;
		}
};

#endif