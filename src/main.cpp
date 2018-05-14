#include "Iterator.h"
#include <iostream>
#include <string>

struct mVal
{
	mVal() :x(0) {};
	mVal(int val) :x(val) {};
	friend std::ostream& operator<<(std::ostream& os, const mVal& val);
	int x;
};

std::ostream& operator<<(std::ostream& os, const mVal& val)
{
	os << val.x;
	return os;
}

int main()
{
	Iterator<mVal*> list;
	list.push_back(new mVal(1));
	list.push_back(new mVal(2));
	list.push_back(new mVal(3));
	list.push_back(new mVal(4));
	list.push_back(new mVal(5));
	list.push_back(new mVal(6));
	list.push_back(new mVal(7));
	list.push_back(new mVal(8));
	for (auto it = list.begin(); it != list.end(); ++it)
	{
		std::cout << **it;
	}

	for (auto it = list.begin(); it != list.end(); ++it)
	{
		delete *it;
	}

	return 0;
}