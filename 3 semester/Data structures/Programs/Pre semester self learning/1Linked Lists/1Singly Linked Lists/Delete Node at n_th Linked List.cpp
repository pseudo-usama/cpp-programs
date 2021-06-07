// Delete Node at n'th Linked List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

struct Node {
	int Data;
	Node *Next;
};

Node *Head;

void Delete_at_nth_Position(int n) {
	Node *Temp;

	Temp = Head;

	if (n == 1) {
		Head = Temp->Next;

		delete Temp;
	}
	else {
		for (int i = 2; i < n; i++) {
			Temp = Temp->Next;
		}
		Node *Temp2 = Temp->Next;

		Temp->Next = Temp2->Next;

		delete Temp2;
	}
}

void Print() {
	Node *Temp = new Node;

	Temp = Head;

	cout << "List  : ";

	while (Temp != NULL) {
		cout << Temp->Data << " ";

		Temp = Temp->Next;
	}
	cout << endl;
}

void main() {
	Head = NULL;

	for (int i = 10; i > 0 ; i--) {	//Makes Nodes of size 10
		Node *Temp = new Node;
		Temp->Data = i;
		Temp->Next = Head;
		Head = Temp;
	}

	Print();

	int n;

	cout << "Enter Location to delete that node  = ";
	cin >> n;

	Delete_at_nth_Position(n);

	Print();
}

