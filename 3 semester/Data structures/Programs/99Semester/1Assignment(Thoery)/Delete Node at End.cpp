// Delete Node at End.cpp : Defines the entry point for the console application.
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
	void Delete_atEnd() {
		if (Head == NULL)
			cout << "List is Empty!\n";
		else {
			if (Head->Next == NULL) {
				delete(Head);

				Head = NULL;
			}
			else {
				LinkedList *temp = Head;

				while (temp->Next->Next != NULL)
					temp = temp->Next;

				delete(temp->Next);

				temp->Next = NULL;
			}
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

	Ob.Delete_atEnd();
	Ob.Display();

	//First we add some Nodes
	Ob.Insert_atStart(1);
	Ob.Display();

	Ob.Delete_atEnd();
	Ob.Display();

	Ob.Insert_atStart(2);
	Ob.Insert_atStart(10);
	Ob.Insert_atStart(-3);
	Ob.Insert_atStart(11);
	Ob.Insert_atStart(21);
	Ob.Insert_atStart(27);
	Ob.Display();

	Ob.Delete_atEnd();
	Ob.Display();

	Ob.Delete_atEnd();
	Ob.Delete_atEnd();
	Ob.Display();
}

