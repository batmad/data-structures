#pragma once
#include <vector>

template <typename T>
class Heap
{
public:
	Heap()
	{

	}

	~Heap()
	{

	}

	T peek()
	{
		return mArray.front();
	}

	void pop()
	{
		if (mArray.size() != 1)
		{
			int pos = mArray.size() - 1;
			std::swap(mArray[pos], mArray[0]);
			mArray.pop_back();
			siftDown();
		}
		else
		if (!mArray.empty())
		{
			mArray.pop_back();
		}
	}

	void insert(T lhs)
	{
		mArray.push_back(lhs);
		siftUp(mArray.size() - 1);		
	}

	void siftUp(int pos)
	{		
		int rootPos = (pos - 1) / 2;		;
		while (rootPos >= 0 && mArray[rootPos] < mArray[pos])
		{
			std::swap(mArray[rootPos], mArray[pos]);
			pos = rootPos;
			rootPos = (pos - 1) / 2; ;
		}
	}

	void siftDown()
	{
		int pos = 0;
		while (pos < mArray.size())
		{
			int left = pos * 2 + 1;
			int right = pos * 2 + 2;
			if (left < mArray.size() && mArray[left] > mArray[pos])
			{
				std::swap(mArray[left], mArray[pos]);
				pos = left;
			}
			else 
			if (right < mArray.size() && mArray[right] > mArray[pos])
			{
				std::swap(mArray[right], mArray[pos]);
				pos = right;
			}
			else
			{
				break;
			}
		}
	}
	

private:
	std::vector<T> mArray;

};