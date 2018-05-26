#pragma once

template <typename T>
class BinarySearchTree
{
public:
	struct Node;
	BinarySearchTree() 
	{
		head = nullptr;
	}

	~BinarySearchTree() 
	{
		cleanUp();
	}

	bool find(T searchData)
	{
		if (!head)
			return false;

		Node* curr = head;
		while (curr->data != searchData)
		{
			if (curr->data > searchData)
			{
				curr = curr->left;
			}
			else 
			if (curr->data < searchData)
			{
				curr = curr->right;
			}
			if (!curr)
			{
				return false;
			}
		}
		return true;
	}

	bool insert(T data)
	{
		if (!head)
		{
			head = new Node(data);
			return true;
		}

		Node* curr = head;

		while (curr->data != data)
		{
			if (curr->data > data)
			{
				if (!curr->left)
				{
					curr->left = new Node(data);
					return true;
				}
				else
				{
					curr = curr->left;
				}
			}
			else
			if (curr->data < data)
			{
				if (!curr->right)
				{
					curr->right = new Node(data);
					return true;
				}
				else
				{
					curr = curr->right;
				}
			}		
		}
		return false;
	}

	void cleanUp()
	{
		deleteNode(head);
		haed = nullptr;
	}

	void deleteNode(Node* node)
	{
		if (!node)
			return;

		deleteNode(node->left);
		deleteNode(node->right);
		delete node;
	}


private:
	struct Node
	{
		Node(T _data) 
		{
			data = _data;
			left = nullptr;
			right = nullptr;
		};
		Node* left;
		Node* right;
		T data;
	};

	Node* head;
};