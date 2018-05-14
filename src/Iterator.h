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
		data = new T[maxSize];
		_begin = data;
		_end = data;
	}
	~Iterator()
	{
		delete[] data;
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
		return _end;
	}

	void push_back(T lhs)
	{				
		data[_size] = lhs;
		++_size;

		if (_size >= maxSize)
		{
			resize();
		}
		else
		{
			_end = data + _size;
		}
	}

private:
	void resize()
	{
		maxSize *= 2;
		T* tData = new T[maxSize];
		for (int i = 0; i < _size; ++i)
		{
			tData[i] = data[i];
		}

		delete[] data;
		data = tData;
		_begin = tData;
		_end = data + _size;
	}

private:
	T* data;
	T* curr;
	T* _begin;
	T* _end;
	int _size;
	int maxSize;
};
