// Linked List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class node {
private:
	int Data;
	node* Next;

public:
	void Insert(int _Data, node **Head) {
		//node* Temp = (*node)malloc(sizeof(struct node));
		node* Temp = /*(node*)*/new node;
		Temp->Data = _Data;

		Temp->Next = *Head;
		*Head = Temp;
	}

	void Print(node* Head) {
		node* Temp = Head;

		cout << "The List is = ";

		while (Temp != NULL) {
			cout << Temp->Data << " ";
			Temp = Temp->Next;
		}
		cout << endl;
	}
};

void main() {
	node* Head;
	Head = NULL;


	int Length;

	cout << "Enter the Number of data items you want to enter    = ";
	cin >> Length;

	for (int i = 0, Data; i < Length; i++) {
		cout << "Enter the Data to save   = ";
		cin >> Data;

		Head->Insert(Data, &Head);
		Head->Print(Head);
	}
}