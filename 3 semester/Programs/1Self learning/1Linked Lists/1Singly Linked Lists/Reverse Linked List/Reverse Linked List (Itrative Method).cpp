// Reverse Linked List (Itrative Method).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

struct Node {
	int Data;
	Node *Next;
};

Node *Head;

void Print() {
	Node *Temp = Head;

	cout << "List is :  ";

	while (Temp != NULL) {
		cout << Temp->Data << " ";

		Temp = Temp->Next;
	}
	cout << endl;
}

void Invert_Linked_List_Itrative_Method() {
	Node *Previous, *Current, *_Next;
	Previous = NULL;
	Current = Head;
	_Next = Head;

	while (Current != NULL) {
		_Next = _Next->Next;
		Current->Next = Previous;
		Previous = Current;
		Current = _Next;
	}
	Head = Previous;
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

	Invert_Linked_List_Itrative_Method();

	Print();
}

