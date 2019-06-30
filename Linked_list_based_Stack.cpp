#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
	int elem;
	Node* next = nullptr;
};

class Stack
{
public:
	Node* top = nullptr;
	int s = 0;
	
	bool empty();
	void push(int);
	void pop();
	void print();
	void size()
	{
		cout << s << endl;
	}
};

bool Stack::empty()
{
	return top == nullptr;
}

void Stack::push(int a)
{
	Node* temp = new Node;
	temp->elem = a;
	s++;

	if (empty())
	{
		top = temp;
		return;
	}

	temp->next = top;
	top = temp;
}

void Stack::pop()
{
	if (empty())
	{
		cout << -1 << endl;
		return;
	}
	
	Node* temp = top;
	top = top->next;
	s--;
	cout << temp->elem << endl;
	delete temp;
}

void Stack::print()
{
	if (empty())
		return;
	Node* temp = top;
	
	while (temp->next != nullptr)
	{
		cout << "|" << temp->elem
			<< "|" << endl;
		temp = temp->next;
	}

	cout << "|" << temp->elem
		<< "|" << endl << "---" << endl;
}

int main()
{
	int many, num;
	string con;
	Stack s;
	cin >> many;
	for (int i = 0; i < many; i++)
	{
		cin >> con;
		if (con == "push")
		{
			cin >> num;
			s.push(num);
		}

			
		else if (con == "pop")
		{

			s.pop();
		}

		
		else if (con == "empty")
		{
			cout << s.empty() << endl;
		}

		else if (con == "size")
		{
			s.size();
		}

		else if (con == "top")
		{
			if (s.empty())
				cout << -1 << endl;
			else
				cout << s.top->elem << endl;
		}
	}
}