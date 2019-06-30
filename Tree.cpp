#include <iostream>
using namespace std;

class Node
{
public:
	int elem = NULL;
	Node* parent = NULL;
	Node* left_child;
	Node* right_child;

	Node() {}
	Node(int a)
	{
		elem = a;
	}

	void setParent(Node* p)
	{
		this->parent = p;
	}

	void insertLeftChild(Node* c)
	{
		this->left_child = c;
	}

	void insertRightChild(Node* c)
	{
		this->right_child = c;
	}


	void removeChild(Node* temp)
	{
		if (this->left_child == temp)
		{
			this->insertLeftChild = nullptr;
			return;
		}
		else if (this->right_child == temp)
		{
			this->right_child = nullptr;
		}
	}
};

class Tree
{
public:
	Node* root;
	int s; //size

	int size()
	{
		return s;
	}
	bool empty()
	{
		return root == nullptr;
	}
	
};