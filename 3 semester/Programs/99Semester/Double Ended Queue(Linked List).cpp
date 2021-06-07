// Double Ended Queue(Linked List).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

struct Node
{
	int a;
	Node *next, *pre;
};

class DoubleEndedQueue
{
	Node *F;
	Node *R;

public:
	DoubleEndedQueue()
	{
		R = NULL;
		F = NULL;
	}

	void FrontEnqueue(int a)
	{
		Node *temp = new Node;
		temp->a = a;
		temp->next = F;
		temp->pre = NULL;
		if (F != NULL)
			F->pre = temp;
		F = temp;

		if (R == NULL)
			R = F;
	}

	void RearEnqueue(int a)
	{
		Node *temp = new Node;
		temp->a = a;
		temp->next = NULL;
		temp->pre = R;
		if (R != NULL)
			R->next = temp;
		R = temp;

		if (F == NULL)
			F = R;
	}

	void FrontDequeue()
	{
		if (F == NULL)
		{
			cout << "Under Flow! Queue is Empty\n";
			return;
		}
		cout << F->a << "\n";
		if (F == R)
		{
			delete F;
			F = R = NULL;
		}
		else
		{
			F = F->next;
			delete F->pre;
			F->pre = NULL;
		}
	}

	void RearDequeue()
	{
		if (F == NULL)
		{
			cout << "Under Flow! Queue is Empty\n";
			return;
		}
		cout << R->a << "\n";

		if (F == R)
		{
			delete R;
			F = R = NULL;
		}
		else
		{
			R = R->pre;
			delete R->next;
			R->next = NULL;
		}
	}

	void Display()
	{
		Node *temp = F;

		cout << "Queue is ";
		while (temp != NULL)
		{
			cout << temp->a << "\t";
			temp = temp->next;
		}
		cout << "\n";
	}
};

int main()
{
	DoubleEndedQueue Queue;

	Queue.RearDequeue();

	Queue.RearEnqueue(1);
	Queue.RearEnqueue(2);
	Queue.RearEnqueue(3);
	Queue.Display();

	Queue.RearDequeue();
	Queue.Display();
}

