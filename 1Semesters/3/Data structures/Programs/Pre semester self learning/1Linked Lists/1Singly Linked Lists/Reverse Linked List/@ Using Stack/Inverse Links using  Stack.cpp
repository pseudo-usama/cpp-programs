// Inverse Links using  Stack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "stack"
using namespace std;

struct Node {
	int Data;
	Node *Next;
};

Node *Head;

void Print() {
	Node *Temp = Head;

	cout << "List is  : ";

	while (Temp != NULL) {
		cout << Temp->Data << " ";

		Temp = Temp->Next;
	}
	cout << endl;
}

void Inverse_Links_using_Stack() {
	if (Head == NULL)  { return; }

	Node *Temp = Head;

	stack<Node*> Ob;

	while (Temp != NULL) {
		Ob.push(Temp);

		Temp = Temp->Next;
	}
	Temp = Ob.top();
	Ob.pop();

	Head = Temp;

	while (!Ob.empty()) {
		Temp->Next = Ob.top();
		Ob.pop();

		Temp = Temp->Next;
	}
	Temp->Next = NULL;	
}

void main() {
	Head = NULL;

	for (int i = 10; i > 0; i--) {
		Node *Temp = new Node;

		Temp->Data = i;
		Temp->Next = Head;
		Head = Temp;
	}
	Print();

	Inverse_Links_using_Stack();

	Print();
}

