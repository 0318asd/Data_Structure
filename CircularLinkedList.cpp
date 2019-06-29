#include <iostream>
using namespace std;

class Node
{
public:
	int elem;
	Node* next;
};

class CircularLinkedList
{
public:
	Node* head = nullptr;
	Node* tail = nullptr;

	bool empty()
	{
		return head == nullptr;
	}

	void addF(int);
	void addB(int);
	void removeF();
	void removeB();
	void print();
};

void CircularLinkedList::addF(int a)
{
	Node* temp = new Node;
	temp->elem = a;

	if (empty())
	{
		head = temp;
		tail = temp;
		tail->next = head;
		return;
	}

	temp->next = head;
	head = temp;
	tail->next = head;
}

void CircularLinkedList::addB(int a)
{
	Node* temp = new Node;
	temp->elem = a;
	if (empty())
	{
		head = temp;
		tail = temp;
		tail->next = head;
		return;
	}

	tail->next = temp;
	tail = temp;
	temp->next = head;
}

void CircularLinkedList::removeF()
{
	if (empty())
	{
		cout << "already empty" << endl;
		return;
	}
	else if (head == tail)
	{
		head = nullptr;
		tail = nullptr;
		return;
	}

	Node* temp = head;

	tail->next = head->next;
	head = head->next;
	delete temp;
}

void CircularLinkedList::removeB()
{
	if (empty())
	{
		cout << "already empty" << endl;
		return;
	}

	else if (head == tail)
	{
		head = nullptr;
		tail = nullptr;
		return;
	}

	Node* temp = head;
	while (temp->next != tail)
	{
		temp = temp->next;
	}
	delete tail;
	tail = temp;
	tail->next = head;
}

void CircularLinkedList::print()
{
	if (empty())
	{
		cout << "empty" << endl;
		return;
	}

	Node* temp = head;
	if (head == tail)
	{
		cout << head->elem << endl;
		return;
	}

	while (temp->next != head)
	{
		cout << temp->elem << " ";
		temp = temp->next;
	}
	cout << temp->elem << endl;

	
}

int main()
{
	int con;
	CircularLinkedList ls;

	for (int i = 0; i < 100; i++)
	{
		cin >> con;

		switch (con)
		{
		case 1:
			cin >> con;
			ls.addF(con);
			break;
		case 2:
			cin >> con;
			ls.addB(con);
			break;
		case 3:
			ls.removeF();
			break;
		case 4:
			ls.removeB();
			break;
		case 5:
			ls.print();
		}
	}
}