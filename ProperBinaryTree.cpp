#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
	int elem;
	int depth = 0;
	Node* parent;
	Node* left_child;
	Node* right_child;

	Node(int a)
	{
		elem = a;
	}
	bool isExternal()
	{
		return left_child == nullptr && right_child == nullptr;
	}
};

class BinaryTree
{
public:
	Node* root;
	vector<Node*> ls;
	int size = 0;

	BinaryTree(int r)
	{
		Node* temp = new Node(r);
		root = temp;
		ls.push_back(root);
	}
	void addLeftNode(int p, int c)
	{
		for (unsigned int i = 0; i < ls.size(); i++)
		{
			if (ls[i]->elem == p)
			{
				Node* temp = new Node(c);
				ls[i]->left_child = temp;
				temp->parent = ls[i];
				ls.push_back(ls[i]->left_child);
				size++;
				return;
			}
		}
	}

	void addRightNode(int p, int c)
	{
		for (unsigned int i = 0; i < ls.size(); i++)
		{
			if (ls[i]->elem == p)
			{
				Node* temp = new Node(c);
				ls[i]->right_child = temp;
				temp->parent = ls[i];
				ls.push_back(ls[i]->right_child);
				size++;
				return;
			}
		}
	}

	void PreorderPrint(Node* r)
	{
		cout << r->elem << " ";
		if (!r->isExternal())
		{
			PreorderPrint(r->left_child);
			PreorderPrint(r->right_child);
		}
	}

	void PostorderPrint(Node* r)
	{
		if (!r->isExternal())
		{
			PostorderPrint(r->left_child);
			PostorderPrint(r->right_child);
		}
		cout << r->elem << " ";
	}

	void InorderPrint(Node* r)
	{
		if (!r->isExternal())
		{
			InorderPrint(r->left_child);
		}

		cout << r->elem << " ";

		if (!r->isExternal())
		{
			InorderPrint(r->right_child);
		}
	}

	void setDepth(Node * r)
	{
		if (r->parent == nullptr)
			r->depth = 0;
		else
			r->depth = r->parent->depth + 1;

		if (!r->isExternal())
		{
			setDepth(r->left_child);
			setDepth(r->right_child);
		}
	}

	void PrintDepth(Node* r)
	{
		if (!r->isExternal())
		{
			PrintDepth(r->left_child);
		}

		cout << r->depth << " ";

		if (!r->isExternal())
		{
			PrintDepth(r->right_child);
		}
	}
};

int main()
{
	int N, M, p, l, r;
	cin >> N >> M;
	cin >> p >> l;

	BinaryTree t(p);

	if(l != 0)
	{
		cin >> r;
		t.addLeftNode(p, l);
		t.addRightNode(p, r);
	}

	for (unsigned int i = 1; i < N; i++)
	{
		cin >> p >> l;

		if (l != 0)
		{
			cin >> r;
			t.addLeftNode(p, l);
			t.addRightNode(p, r);
		}
	}

	t.setDepth(t.root);

	for (int i = 0; i < M; i++)
	{
		cin >> N;
		if (N == 1)
		{
			t.PreorderPrint(t.root);
			cout << endl;
		}

		else if (N == 2)
		{
			t.PostorderPrint(t.root);
			cout << endl;
		}

		else if (N == 3)
		{
			t.InorderPrint(t.root);
			cout << endl;
		}

		else if (N == 4)
		{
			t.PrintDepth(t.root);
			cout << endl;
		}
	}
}