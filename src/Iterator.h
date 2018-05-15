#pragma once
#include <iterator>

#define SIZE 8;

template <typename T>
class DynamicArray : public std::iterator<std::input_iterator_tag, T>
{
public:
	DynamicArray()
	{
		_size = 0;
		_maxSize = SIZE;
		_begin = new T[_maxSize];
	}
	DynamicArray(const DynamicArray& lhs)
	{
		delete[] _begin;
		_begin = lhs._begin;
		_size = lhs._size;
		_maxSize = lhs._maxSize;	
	}
	~DynamicArray()
	{
		delete[] _begin;
		_size = 0;
	}

	DynamicArray& operator++()
	{
		++_begin;
		return *this;
	}

	DynamicArray operator++(int)
	{
		DynamicArray temp(*this);
		operator++();
		return temp;
	}

	bool operator==(const DynamicArray& lhs) const
	{		
		if (lhs._size != _size)
		{
			return false;
		}
		for (size_t i = 0; i < _size; ++i)
		{
			if (lhs._begin[i] != _begin[i])
			{
				return false;
			}
		}
		return true;
	}

	bool operator!=(const DynamicArray& lhs) const
	{
		return !(*this == lhs);
	}

	T& operator*()
	{
		return *_begin;
	}

	int size()
	{
		return _size;
	}
	bool empty()
	{
		return _size == 0;
	}
	T* begin()
	{
		return _begin;
	}
	T* end()
	{
		return _begin + _size;
	}

	void push_back(T lhs)
	{				
		_begin[_size] = lhs;
		++_size;

		if (_size >= _maxSize)
		{
			resize();
		}
	}

private:
	void resize()
	{
		_maxSize *= 2;
		T* tData = new T[_maxSize];
		for (size_t i = 0; i < _size; ++i)
		{
			tData[i] = _begin[i];
		}

		delete[] _begin;
		_begin = tData;
	}

private:
	T* _begin;
	size_t _size;
	size_t _maxSize;
};
