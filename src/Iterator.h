#pragma once

#define SIZE 8;

template <typename T>
class Iterator
{
public:
	Iterator()
	{
		_size = 0;
		maxSize = SIZE;
		_begin = new T[maxSize];
	}
	~Iterator()
	{
		delete[] _begin;
		_size = 0;
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

		if (_size >= maxSize)
		{
			resize();
		}
	}

private:
	void resize()
	{
		maxSize *= 2;
		T* tData = new T[maxSize];
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
	size_t maxSize;
};
