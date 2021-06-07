// Insert at Specific Location.cpp : Defines the entry point for the console application.
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
	void Insert_at_n(int _Data, int n) {
		LinkedList *NewNode = new LinkedList;

		NewNode->Data = _Data;

		if (n < 2) {
			NewNode->Next = Head;
			Head = NewNode;

			if (n < 1)
				cout << "\nYou entered location less then 1. So Data Saved at Start.\n";
		}
		else {
			if (Head == NULL && n > 1) {
				cout << "\nList is empty and you entered location greater then 1. So Data Saved at Start.\n";

				NewNode->Next = Head;
				Head = NewNode;
			}
			else {
				LinkedList *temp = Head;

				for (int i = 2; i < n; i++) {
					if (temp->Next != NULL)
						temp = temp->Next;
					else {
						cout << "\nYou entered Location Greater then List Length. So Data is Saved at End.\n";

						NewNode->Next = NULL;
						temp->Next = NewNode;

						return;
					}
				}
				NewNode->Next = temp->Next;
				temp->Next = NewNode;
			}
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

	Ob.Insert_at_n(1, 4);
	Ob.Display();

	Ob.Insert_at_n(2, 1);
	Ob.Display();

	Ob.Insert_at_n(6, 1);
	Ob.Display();

	Ob.Insert_at_n(9, 3);
	Ob.Display();

	Ob.Insert_at_n(3, -1);
	Ob.Display();

	Ob.Insert_at_n(0, 2);
	Ob.Display();

	Ob.Insert_at_n(-1, 5);
	Ob.Display();

	Ob.Insert_at_n(10, 1);
	Ob.Display();
}

