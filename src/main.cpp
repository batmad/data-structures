#include "BinarySearchTree.h"
#include <iostream>
#include <string>

struct mVal
{
	mVal() :x(0) {};
	mVal(int val) :x(val) {};
	
	bool operator<(const mVal& val)
	{
		return x < val.x;
	}

	bool operator>(const mVal& val)
	{
		return !(*this < val);
	}

	friend bool operator<(const mVal& lhs, const mVal& rhs);
	friend bool operator>(const mVal& lhs, const mVal& rhs);
	friend std::ostream& operator<<(std::ostream& os, const mVal& val);
	int x;
};

bool operator<(const mVal& lhs, const mVal& rhs)
{
	return lhs.x < rhs.x;
}

bool operator>(const mVal& lhs, const mVal& rhs)
{
	return lhs.x > rhs.x;
}

std::ostream& operator<<(std::ostream& os, const mVal& val)
{
	os << val.x;
	return os;
}

int main()
{
	BinarySearchTree<int> list;
	list.insert(1);
	list.insert(2);
	list.insert(3);
	list.insert(4);
	list.insert(5);
	list.insert(6);
	list.insert(7);
	list.insert(8);
	
	return 0;
}