// Insert Node at Start.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

class LinkedList {
private:
	int Data;
	LinkedList *Next;
	
	LinkedList *Head = NULL;

public:
	void Insert_atStart(int _Data) {
		LinkedList *NewNode = new LinkedList;

		NewNode->Data = _Data;
		NewNode->Next = Head;
		Head = NewNode;
	}

	void Display() {
		LinkedList *temp = Head;

		cout << "Linked List is   : ";
		while (temp!=NULL) {
			cout << temp->Data << "  ";

			temp = temp->Next;
		}
		cout << endl;
	}
};

void main() {
	LinkedList Ob;

	Ob.Display();

	Ob.Insert_atStart(1);
	Ob.Insert_atStart(2);
	Ob.Insert_atStart(6);
	Ob.Insert_atStart(9);
	Ob.Insert_atStart(3);
	Ob.Insert_atStart(0);
	Ob.Insert_atStart(-1);
	Ob.Insert_atStart(10);

	Ob.Display();
}

