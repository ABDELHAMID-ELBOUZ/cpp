#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template<typename T>
class Array
{
	private:
		T* Data;
		unsigned int Size;

	public:
		Array() : Data(NULL), Size(0)
		{

		}

		Array(unsigned int n) : Data(new T[n]()), Size(n)
		{
			
		}

		Array(Array const& other) : Data(new T[other.Size]()), Size(other.Size)
		{
			for (unsigned int i = 0; i < Size; ++i)
				Data[i] = other.Data[i];
		}

		Array& operator=(Array const& other)
		{
			if (this != &other)
			{
				delete[] Data;
				Data = new T[other.Size]();
				Size = other.Size;
				for (unsigned int i = 0; i < Size; ++i)
					Data[i] = other.Data[i];
			}
			return *this;
		}

		~Array()
		{
			delete[] Data;
		}

		T& operator[](unsigned int i)
		{
			if (i >= Size)
				throw std::exception();
			return Data[i];
		}

		T const& operator[](unsigned int i) const
		{
			if (i >= Size)
				throw std::exception();
			return Data[i];
		}

		unsigned int size() const
		{
			return Size;
		}
};

#endif