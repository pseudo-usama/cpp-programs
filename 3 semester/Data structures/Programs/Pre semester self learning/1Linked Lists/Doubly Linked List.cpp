// Doubly Linked List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

struct Node {
	int Data;
	Node *Next;
	Node *Prev;
};

Node *Head;

void Insert_Node_at_Head(int _Data) {
	Node *NewNode = new Node;

	NewNode->Data = _Data;
	NewNode->Next = NULL;
	NewNode->Prev = NULL;

	if (Head == NULL) {
		Head = NewNode;
	}
	else {
		NewNode->Next = Head;
		Head->Prev = NewNode;
		Head = NewNode;
	}
}

void Insert_Node_at_Tail(int _Data) {
	Node *NewNode = new Node;

	NewNode->Data = _Data;
	NewNode->Next = NULL;
	NewNode->Prev = NULL;

	if (Head == NULL) {
		Head = NewNode;
	}
	else {
		Node *Temp = Head;

		while (Temp->Next != NULL) {
			Temp = Temp->Next;
		}
		Temp->Next = NewNode;
		NewNode->Prev = Temp;
	}
}

void Insert_Node_at_nth_Position(int _Data, int n) {
	if (n == 1) {
		Insert_Node_at_Head(_Data);

		return;
	}

	Node *NewNode = new Node;

	NewNode->Data = _Data;

	Node *Temp = Head;

	for (int i = 2; i < n; i++) {
		Temp = Temp->Next;
	}
	
	if (Temp->Next != NULL) {
		NewNode->Next = Temp->Next;
		NewNode->Prev = Temp;
		Temp->Next->Prev = NewNode;
		Temp->Next = NewNode;
	}
	else {
		Temp->Next = NewNode;
		NewNode->Prev = Temp;
		NewNode->Next = NULL;
	}
}

void Forward_Print() {
	Node *Temp = Head;

	cout << "Forward List  : ";

	while (Temp!=NULL) {
		cout << Temp->Data << " ";

		Temp = Temp->Next;
	}
	cout << endl;
}

void Reverse_Print() {
	cout << "Reverse List  : ";

	if (Head != NULL) {

		Node *Temp = Head;

		while (Temp->Next != NULL) {
			Temp = Temp->Next;
		}

		while (Temp != NULL) {
			cout << Temp->Data << " ";
			Temp = Temp->Prev;
		}
	}
	cout << endl;
}

void Invert_Doubly_Linked_List(Node *Temp) {
	if (Temp == NULL) { return; }

	if (Temp->Next == NULL) {
		Node *Ptr;
		Ptr = Temp->Prev;
		Temp->Prev = Temp->Next;
		Temp->Next = Ptr;

		Head = Temp;
		return;
	}
	Invert_Doubly_Linked_List(Temp->Next);

	Node *Ptr;
	Ptr = Temp->Prev;
	Temp->Prev = Temp->Next;
	Temp->Next = Ptr;
}

void main() {
	Head = NULL;
		
	Insert_Node_at_Head(4);
	Insert_Node_at_Head(2);
	Insert_Node_at_Head(1);				//List is  : 1 2 4 

	Insert_Node_at_Tail(9);
	Insert_Node_at_Tail(7);
	Insert_Node_at_Tail(6);				//List is  : 1 2 4 9 7 6

	Insert_Node_at_nth_Position(5, 1);	//List is  : 5 1 2 4 9 7 6
	Insert_Node_at_nth_Position(3, 6);	//List is  : 5 1 2 4 9 3 7 6
	Insert_Node_at_nth_Position(8, 9);	//List is  : 5 1 2 4 9 3 7 6 8

	Forward_Print();
	Reverse_Print();

	Invert_Doubly_Linked_List(Head);		//List is  : 8 6 7 3 9 4 2 1 5 

	Forward_Print();
	Reverse_Print();
}

