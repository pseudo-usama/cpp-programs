// Delete nth Node.cpp : Defines the entry point for the console application.
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
	void Delete_at_nth(int n) {
		if (Head == NULL)
			cout << "List is Empty!\n";
		else if (n < 1)
			cout << "\nError! You entered Location less then 1.\n";
		else if (n == 1) {
			LinkedList *temp = Head;

			Head = Head->Next;
			delete(temp);
		}
		else {
			LinkedList *temp = Head;

			for (int i = 2; i < n; i++) {
				if (temp->Next != NULL)
					temp = temp->Next;
				else {
					cout << "\nError! You entered Location Greater then List Length.\n";
					return;
				}
			}
			LinkedList *To_be_Deleted = temp->Next;

			temp->Next = temp->Next->Next;
			delete(To_be_Deleted);
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

	Ob.Delete_at_nth(4);
	Ob.Display();


	//First we add some Nodes

	Ob.Insert_atStart(1);
	Ob.Display();
	Ob.Delete_at_nth(1);

	Ob.Insert_atStart(4);
	Ob.Insert_atStart(9);
	Ob.Display();
	Ob.Delete_at_nth(1);
	Ob.Display();

	Ob.Insert_atStart(-10);
	Ob.Insert_atStart(11);
	Ob.Insert_atStart(23);
	Ob.Display();
	Ob.Delete_at_nth(3);

	Ob.Insert_atStart(99);
	Ob.Insert_atStart(10);
	Ob.Insert_atStart(110);
	Ob.Insert_atStart(31);
	Ob.Insert_atStart(22);
	Ob.Display();
	Ob.Delete_at_nth(3);

	Ob.Delete_at_nth(-3);
	Ob.Display();
}

