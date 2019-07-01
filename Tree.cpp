#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node
{
public:
	int elem;
	Node* parent;
	vector<Node*> child;
	int depth = 0;

	Node() {}
	Node(int a) { elem = a; }

	void setParent(Node* a)
	{
		this->parent = a;
	}

	void setChild(Node * a)
	{
		this->child.push_back(a);
	}

};

class Tree
{
public:
	Node* root;
	vector<Node*> ls;

	bool empty()
	{
		return root == nullptr;
	}

	void addNode(int parent_data, int child_data)
	{

		for (unsigned int i = 0; i < ls.size(); i++)
		{
			if (ls[i]->elem == parent_data)
			{
				Node* temp = new Node(child_data);
				ls[i]->setChild(temp);
				temp->setParent(ls[i]);
				ls.push_back(temp);
			}
		}
	}

	void removeNode(int data)
	{
		for (unsigned int i = 0; i < ls.size(); i++)
		{
			if (ls[i]->elem == data)
			{
				Node* temp = ls[i];
				for (unsigned int j = 0; j < temp->child.size(); j++)
				{
					temp->child[j]->parent = temp->parent;
					temp->parent->setChild(temp->child[j]);
				}
				delete temp;
			}
		}
	}

	void print_depth(int data)
	{
		int d = 0;
		for (unsigned int i = 0; i < ls.size(); i++)
		{
			if (ls[i]->elem == data)
			{
				Node* temp = ls[i];

				while (temp != root)
				{
					d++;
					temp = temp->parent;
				}

			}
		}

		cout << d << endl;
	}
	void print(int data)
	{
		for (unsigned int i = 0; i < ls.size(); i++)
		{
			if (ls[i]->elem == data)
			{

				Node* temp = ls[i];

				if (temp->child.size() == 0)
				{
					cout << 0 << endl;
					return;
				}

				for (unsigned int j = 0; j < temp->child.size(); j++)
				{
					cout << temp->child[j]->elem << " ";
				}
				cout << endl;
				delete temp;

				break;
			}
		}
	}
};


int main()
{
	Tree t;
	int N, M, parent, child = -1;
	cin >> N >> M;
	cin >> parent;
	Node* temp = new Node(parent);
	t.root = temp;
	t.ls.push_back(temp);

	cin >> child;
	while (child != 0)
	{
		t.addNode(parent, child);
		cin >> child;
	}

	for (int i = 1; i < N; i++)
	{

		cin >> parent;
		cin >> child;
		while (child != 0)
		{
			t.addNode(parent, child);
			cin >> child;
		}
	}

	for (int i = 0; i < M; i++)
	{
		cin >> parent;
		t.print_depth(parent);
	}
}