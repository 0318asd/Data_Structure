#include <iostream>
using namespace std;

class Queue
{
public:
	int arr[5];
	int f = 0, r = 0, s = 0;
	
	bool empty();
	void enqueue(int);
	void dequeue();
	void front();
	void rear();
	void size();
	void print();

};

bool Queue::empty()
{
	return s == 0;
}

void Queue::enqueue(int a)
{
	//비어있는 경우
	if (empty())
	{
		arr[f] = a;
		r = (r + 1) % 5;
		s++;
		return;
	}
	//꽉 찬 경우
	else if (s == 5)
	{
		cout << "full" << endl;
		return;
	}
	//그냥
	arr[r] = a;
	r = (r + 1) % 5;
	s++;
	cout << "enqueue " << a << endl;
}

void Queue::dequeue()
{
	if (empty())
	{
		cout << "already empty" << endl;
		return;
	}

	cout << arr[f] << endl;
	f = (f + 1) % 5;
	s--;
}

void Queue::front()
{
	cout << arr[f] << endl;
}

void Queue::rear()
{
	if (r == 0)
	{

		cout << arr[4] << endl;
		return;
	}
	cout << arr[r - 1] << endl;
}

void Queue::size()
{
	cout << s << endl;
}

void Queue::print()
{
	int temp = f;

	if (empty())
	{
		cout << "empty" << endl;
		return;
	}

	cout << "<- ";

	if (f == r)
	{
		for (int i = 0; i < 5; i++)
		{
			cout << arr[temp] << " ";
			temp = (temp + 1) % 5;
		}
	}

	else
	{
		while (temp != r)
		{
			cout << arr[temp] << " ";
			temp = (temp + 1) % 5;
		}
	}
	
	cout << " <-" << endl;
}

int main()
{
	int con;
	Queue q;

	for (int i = 0; i < 100; i++)
	{
		cin >> con;

		switch (con)
		{
		case 1:
			cin >> con;
			q.enqueue(con);
			break;

		case 2:
			q.dequeue();
			cout << "dequeue" << endl;
			break;

		case 3:

			cout << "front : ";
			q.front();
			break;

		case 4:

			cout << "rear : ";
			q.rear();
			break;

		case 5:

			cout << "size : ";
			q.size();
			break;

		case 6:
			q.print();
		}
	}
}