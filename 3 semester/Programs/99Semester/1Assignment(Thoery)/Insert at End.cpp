// Insert at End.cpp : Defines the entry point for the console application.
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
	void Insert_atEnd(int _Data) {
		LinkedList *NewNode = new LinkedList;

		NewNode->Data = _Data;
		NewNode->Next = NULL;

		if (Head == NULL)
			Head = NewNode;
		else {
			LinkedList *temp = Head;

			while (temp->Next != NULL)
				temp = temp->Next;

			temp->Next = NewNode;
		}
	}

	void Display() {
		LinkedList *temp = Head;

		cout << "Linked List is   : ";
		while (temp != NULL) {
			cout << temp->Data << "  ";

			temp = temp->Next;
		}
		cout << endl;
	}
};

void main() {
	LinkedList Ob;

	Ob.Display();

	Ob.Insert_atEnd(1);
	Ob.Insert_atEnd(2);
	Ob.Insert_atEnd(6);
	Ob.Insert_atEnd(9);
	Ob.Insert_atEnd(3);
	Ob.Insert_atEnd(0);
	Ob.Insert_atEnd(-1);
	Ob.Insert_atEnd(10);

	Ob.Display();
}

