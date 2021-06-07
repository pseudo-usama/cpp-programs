// Double Linked List-Assignment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

class DoubleLinkedList {
private:
	class Node {
	public:
		int Data;
		Node *Next;
		Node *Prev;

		//Constructor
		Node(int _Data) {
			this->Data = _Data;
			this->Next = this->Prev = NULL;
		}
	};

	Node *Head;

public:
	void DoubleLinkedList::Insert_atStart(int _Data);
	void DoubleLinkedList::Insert_atEnd(int _Data);
	void DoubleLinkedList::Insert_at_nth(int _Data, int n);
	void DoubleLinkedList::Display();
	void DoubleLinkedList::Print_Reverse();

	//Constructor
	DoubleLinkedList() {
		Head = NULL;
	}
};

void main() {
	DoubleLinkedList Ob;

	//Ob.Display();
	//Ob.Print_Reverse();

	Ob.Insert_at_nth(22, 0);
	Ob.Insert_at_nth(100, 1);
	Ob.Insert_at_nth(12, 3);
	Ob.Insert_at_nth(22, 8);
	Ob.Display();

	Ob.Insert_atStart(1);
	Ob.Insert_atStart(2);
	Ob.Insert_atStart(8);
	Ob.Insert_atStart(9);
	Ob.Display();

	Ob.Insert_atEnd(2);
	Ob.Insert_atEnd(-4);
	Ob.Insert_atEnd(11);
	Ob.Insert_atEnd(21);
	Ob.Display();

	Ob.Print_Reverse();
}

void DoubleLinkedList::Insert_atStart(int _Data) {
	Node *NewNode = new Node(_Data);
		
	NewNode->Next = Head;
	if (Head != NULL) Head->Prev = NewNode;
	Head = NewNode;
}

void DoubleLinkedList::Insert_atEnd(int _Data) {
	Node *NewNode = new Node(_Data);

	if (Head == NULL)	//If the list is empty
		Head = NewNode;	
	else
	{
		Node *temp = Head;
		while (temp->Next != NULL)
			temp = temp->Next;

		temp->Next = NewNode;
		NewNode->Prev = temp;
	}
}

void DoubleLinkedList::Insert_at_nth(int _Data, int n) {
	Node *NewNode = new Node(_Data);

	if (n < 2) {
		if (n < 1)
			cout << "You entered Location less then one so Data saved at Start.\n";
		NewNode->Next = Head;
		if (Head != NULL) Head->Prev = NewNode;
		Head = NewNode;
	}//End if
	else if (Head == NULL) {
		if (n > 1)
			cout << "You entered Location greater then one and List is empty so Data saved at Start.\n";
		NewNode->Next = Head;
		if (Head != NULL) Head->Prev = NewNode;
		Head = NewNode;
	}//End else if
	else {
		Node *temp = Head;
		for (int i = 2; i < n; i++) {
			if (temp->Next != NULL)
				temp = temp->Next;
			else {
				cout << "You entered Location greater then List size so data is saved at End.\n";
				temp->Next = NewNode;
				NewNode->Prev = temp;
				return;
			}//End else
		}//End for Loop
		if (temp->Next == NULL) {
			temp->Next = NewNode;
			NewNode->Prev = temp;
		}//End if
		else {
			temp->Next->Prev = NewNode;	//Creating link with next node
			NewNode->Next = temp->Next;

			temp->Next = NewNode;	//Creating link with previous node
			NewNode->Prev = temp;
		}//End Inner else
	}//End outer else
}//End Insert_at_nth Fn

void DoubleLinkedList::Display() {
	cout << "Double Linked List is  : ";
	if (Head != NULL) {
		Node *temp = Head;

		while (temp != NULL) {
			cout << temp->Data << ", ";
			temp = temp->Next;
		}
	}//End if
	cout << endl;
}//End Display Fn

void DoubleLinkedList::Print_Reverse() {
	cout << "Double Linked List(in Reverse Order)  : ";
	if (Head != NULL) {
		Node *temp = Head;

		while (temp->Next != NULL)
			temp = temp->Next;

		while (temp != NULL) {
			cout << temp->Data << ", ";
			temp = temp->Prev;
		}
	}//End if
	cout << endl;
}