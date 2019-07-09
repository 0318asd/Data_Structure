#include <iostream>
using namespace std;

class Node
{
public:
	Node* parent = nullptr;
	Node* left = nullptr;
	Node* right = nullptr;
	int elem;

	Node(int a)
	{
		elem = a;
	}

	Node() {}

	bool isExternal()
	{
		return left == nullptr && right == nullptr;
	}

};



class BinarySearchTree
{
public:
	int count = 0;
	Node* root;
	BinarySearchTree(int a)
	{
		Node* temp = new Node(a);
		root = temp;
	}

	void insert(int a, Node* n)
	{
		Node* temp = new Node(a);

		if (a < n->elem)
		{
			if (n->left == nullptr)
			{
				n->left = temp;
				temp->parent = n;
			}

			else insert(a, n->left);
		}

		else
		{
			if (n->right == nullptr)
			{
				n->right = temp;
				temp->parent = n;
			}

			else insert(a, n->right);
		}
	}



	Node* MIN(Node* a)
	{
		if (a->left != nullptr)
		{
			count++;
			return MIN(a->left);
		}

		else return a;
	}



	Node* search(int a, Node* temp)
	{
		if (temp->elem > a) return search(a, temp->left);

		else if (temp->elem < a) return search(a, temp->right);

		else return temp;

		if (temp->isExternal()) return nullptr;
	}



	void change(Node* p, Node* n)
	{
		if (p == root)
		{
			root = n;
			n->parent = nullptr;
			return;
		}

		else if (p->parent->left == p) p->parent->left = n;

		else if (p->parent->right == p)	p->parent->right = n;

		if (n != nullptr) n->parent = p->parent;
	}



	void remove(int a)
	{
		Node* temp1 = search(a, root);

		if (temp1->isExternal())
		{
			change(temp1, nullptr);
			delete temp1;
			return;
		}



		else if (temp1->left != nullptr && temp1->right == nullptr)
		{
			change(temp1, temp1->left);
			delete temp1;
			return;
		}



		else if (temp1->left == nullptr && temp1->right != nullptr)
		{
			change(temp1, temp1->right);
			delete temp1;
			return;
		}



		else if (!temp1->isExternal())
		{
			Node* temp2 = MIN(temp1->right);

			int temp = temp2->elem;
			remove(temp2->elem);
			temp1->elem = temp;
		}
	}
};



int main()
{
	int N, M, num;
	cin >> N >> M >> num;
	BinarySearchTree T(num);

	for (int i = 1; i < N; i++)
	{
		cin >> num;
		T.insert(num, T.root);
	}

	for (int i = 0; i < M; i++)
	{
		cin >> num;
		T.remove(num);
		cout << T.count << endl;
	}
}