#include <iostream>
using namespace std;

class Node
{
public:
	int elem;
	Node* next;
	Node* prev;
};

class DoublyLinkedList
{
public:
	Node* header = new Node;
	Node* trailer = new Node;
	DoublyLinkedList();
	bool empty();
	void addF(int);
	void addB(int);
	void removeF();
	void removeB();
	void print();
};

DoublyLinkedList::DoublyLinkedList()
{
	header->next = trailer;
	trailer->prev = header;
}

bool DoublyLinkedList::empty()
{
	return header->next == trailer && trailer->prev == header;
}

void DoublyLinkedList::addF(int a)
{
	Node* temp = new Node;
	temp->elem = a;

	if (empty())
	{
		temp->next = trailer;
		temp->prev = header;
		trailer->prev = temp;
		header->next = temp;
		cout << "addFront " << a << endl;
		return;
	}

	temp->next = header->next;
	temp->prev = header;
	header->next->prev = temp;
	header->next = temp;
	cout << "addFront " << a << endl;
}

void DoublyLinkedList::addB(int a)
{
	Node* temp = new Node;
	temp->elem = a;

	if (empty())
	{
		temp->next = trailer;
		temp->prev = header;
		trailer->prev = temp;
		header->next = temp;
		cout << "addBack " << a << endl;
		return;
	}

	temp->next = trailer;
	temp->prev = trailer->prev;
	trailer->prev->next = temp;
	trailer->prev = temp;
	cout << "addFront " << a << endl;

}

void DoublyLinkedList::removeF()
{
	if (empty())
	{
		cout << "already empty" << endl;
		return;
	}
	Node* temp = header->next;
	header->next->next->prev = header;
	header->next = header->next->next;
	delete temp;
	cout << "remove Front" << endl;
}

void DoublyLinkedList::removeB()
{
	if (empty())
	{
		cout << "already empty" << endl;
		return;
	}

	Node* temp = trailer->prev;
	trailer->prev->prev->next = trailer;
	trailer->prev = trailer->prev->prev;
	delete temp;
	cout << "removeBack" << endl;
}

void DoublyLinkedList::print()
{
	if (empty())
	{
		cout << "empty" << endl;
		return;
	}
	Node* temp = header->next;
	cout << "<- header ->";
	while (temp->next != trailer)
	{
		cout << " <- " << temp->elem << " ->";
		temp = temp->next;
	}
	cout << " <- " << temp->elem << " ->" <<
		" <- trailer ->" << endl;
}

int main()
{
	int con;
	DoublyLinkedList ls;

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