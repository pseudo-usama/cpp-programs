// Invers Data using Stack.cpp : Defines the entry point for the console application.
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

void Invert_Linked_List_Data_using_Stack() {
	Node *Temp = new Node;
	Temp = Head;

	stack<int> Ob;

	while (Temp != NULL) {
		Ob.push(Temp->Data);

		Temp = Temp->Next;
	}

	Temp = Head;

	while (Temp != NULL) {
		Temp->Data = Ob.top();
		Ob.pop();

		Temp = Temp->Next;
	}
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

	Invert_Linked_List_Data_using_Stack();

	Print();
}

