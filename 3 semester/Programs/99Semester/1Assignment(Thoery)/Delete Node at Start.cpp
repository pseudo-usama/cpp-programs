// Delete Node at Start.cpp : Defines the entry point for the console application.
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
	void Delete_atStart() {
		if (Head == NULL)
			cout << "List is Empty!\n";
		else {
			LinkedList *To_be_Delete = Head;

			Head = To_be_Delete->Next;

			delete(To_be_Delete);
		}
	}	
	void Insert_atStart(int _Data) {
		LinkedList *NewNode = new LinkedList;

		NewNode->Data = _Data;
		NewNode->Next = Head;
		Head = NewNode;
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
	
	Ob.Delete_atStart();

	//First we add some Nodes
	Ob.Insert_atStart(1);
	Ob.Display();

	Ob.Insert_atStart(2);
	Ob.Insert_atStart(5);
	Ob.Insert_atStart(-10);
	Ob.Insert_atStart(11);
	Ob.Insert_atStart(19);
	Ob.Insert_atStart(20);
	Ob.Display();

	Ob.Delete_atStart();
	Ob.Delete_atStart();
	Ob.Display();
}

