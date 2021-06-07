// Linked List Insertion at n'th Position.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

struct Node{
	int Data;
	Node *Next;
};

Node *Head;

void _Insert_at_nth_Position(int _Data, int n) {
	Node *Temp = new Node;

	Temp->Data = _Data;

	if (n == 1) {
		Temp->Next = Head;
		Head = Temp;
	}
	else {
		Node *Temp2 = Head;

		for (int i = 2; i < n; i++) {
			Temp2 = Temp2->Next;
		}
		Temp->Next = Temp2->Next;
		Temp2->Next = Temp;
	}
}

void Print_Linked_List() {
	Node *Temp = Head;

	cout << "The Linked List is  : ";

	while (Temp != NULL) {
		cout << Temp->Data << " ";
		Temp = Temp->Next;
	}
	cout << endl;
}

void  main() {
	Head = NULL;

	_Insert_at_nth_Position(1, 1);		//List 1
	_Insert_at_nth_Position(2, 1);		//List 2 1
	_Insert_at_nth_Position(7, 3);		//List 2 1 7
	_Insert_at_nth_Position(-1, 2);		//List 2 -1 1 7
	_Insert_at_nth_Position(100, 4);	//List 2 -1 1 100 7

	Print_Linked_List();
}

