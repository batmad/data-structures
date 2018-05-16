#pragma once
#include <iterator>

template <typename T>
class LinkedList : public std::iterator<std::input_iterator_tag, T>
{
public:
	struct Node;
	LinkedList()
	{
		head = nullptr;
		_size = 0;
	}

	LinkedList(Node* node)
	{
		head = node;
	}

	LinkedList(const LinkedList& lhs)
	{
		Node* curr = head;
		while (curr)
		{
			Node* next = curr->next;
			delete curr;
			curr = next;
		}
		head = lhs.head;
		_size = lhs._size;
	}

	~LinkedList()
	{
		Node* curr = head;
		while (curr)
		{
			Node* next = curr->next;
			delete curr;
			curr = next;
		}
	}
	LinkedList& operator++()
	{
		head = head->next;
		return *this;
	}
	LinkedList& operator++(int)
	{
		LinkedList temp(*this);
		operator++();
		return temp;
	}
	bool operator==(const LinkedList& lhs)
	{
		if (_size != lhs._size)
			return false;
		Node* curr = head;
		Node* currLhs = lhs.head;
		while (curr)
		{
			if (curr != currLhs)
				return false;
			currLhs = currLhs->next;
			curr = curr->next;
		}
		return true;
	}

	bool operator!=(const LinkedList& lhs)
	{
		return !(*this == lhs);
	}

	T& operator*()
	{
		return head->value;
	}

	size_t size()
	{
		return _size;
	}

	bool empty()
	{
		return head;
	}

	LinkedList<T> begin()
	{
		return LinkedList<T>(head);
	}

	LinkedList<T> end()
	{
		return LinkedList<T>();
	}

	void push_back(T lhs)
	{
		++_size;
		if (head)
		{
			Node* curr = head;
			while (curr->next)
			{
				curr = curr->next;
			}
			curr->next = new Node(lhs);
		}
		else
		{
			head = new Node(lhs);
		}
	}

	struct Node
	{
		Node(T val) 
		{
			value = val;
			next = nullptr;
		}
		bool operator==(const Node& lhs)
		{
			return value == lhs.value;
		}
		Node* next;
		T value;
	};
	Node* head;
	size_t _size;
};