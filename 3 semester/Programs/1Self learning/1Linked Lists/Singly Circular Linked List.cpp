// Singly Circular Linked List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

class CircularLinkedList {
private:
	int Data;
	CircularLinkedList *Next;

	CircularLinkedList *Head = NULL;

public:
	void Insert_at_Start(int _Data) {
		CircularLinkedList *NewNode = new CircularLinkedList;

		NewNode->Data = _Data;
		NewNode->Next = Head;

		if (Head == NULL) {
			NewNode->Next = NewNode;
		}
		else {
			CircularLinkedList *Temp = Head;

			while (Temp->Next != Head) { Temp = Temp->Next; }

			Temp->Next = NewNode;
		}
		Head = NewNode;
	}
	void Insert_at_End(int _Data) {
		CircularLinkedList *NewNode = new CircularLinkedList;

		NewNode->Data = _Data;

		if (Head == NULL) {
			Head = NewNode;
			NewNode->Next = NewNode;
		}
		else {
			CircularLinkedList *Temp = Head;

			while (Temp->Next != Head) { Temp = Temp->Next; }

			Temp->Next = NewNode;
			NewNode->Next = Head;
		}
	}
	void Insert_at_nth(int _Data, int n) {
		if (n < 1) { cout << "Error! Enter Location Greater then 0." << endl; return; }
		
		CircularLinkedList *NewNode = new CircularLinkedList;

		NewNode->Data = _Data;

		CircularLinkedList *Temp = Head;

		if (n == 1) {
			if (Head == NULL) {
				Head = NewNode;
				NewNode->Next = NewNode;
			}
			else {
				NewNode->Next = Head;

				while (Temp->Next != Head) { Temp = Temp->Next; }
				Temp->Next = NewNode;

				Head = NewNode;
			}
		}
		else {
			for (int i = 2; i < n; i++) {
				if (Temp->Next != Head) {
					Temp = Temp->Next;
				}
				else {
					cout << "Sorry you entered a Location Greater then Linked Lists Size" << endl;

					return;
				}
			}
			NewNode->Next = Temp->Next;
			Temp->Next = NewNode;
		}
	}

	void Delete_at_First() {
		if (Head == NULL) {
			return;
		}
		else if (Head == Head->Next) {
			delete(Head);

			Head = NULL;
		}
		else {
			CircularLinkedList *Temp = Head;

			while (Temp->Next != Head) { Temp = Temp->Next; }

			Temp->Next = Temp->Next->Next;

			delete(Head);

			Head = Temp->Next;
		}
	}
	void Delete_at_End() {
		if (Head == NULL) {
			return;
		}
		else if (Head == Head->Next) {
			delete(Head);

			Head = NULL;
		}
		else {
			CircularLinkedList *Temp = Head;

			while (Temp->Next->Next != Head) { Temp = Temp->Next; }

			delete (Temp->Next);

			Temp->Next = Head;
		}
	}
	void Delete_at_nth(int n) {
		if (n < 1) { cout << "Enter a Location Greater then 0." << endl; return; }
		
		if (Head == NULL) { return; }
				
		if (n == 1) {
			if (Head->Next == Head) {
				delete(Head);

				Head = NULL;
			}
			else {
				CircularLinkedList *Will_Delete;
				CircularLinkedList *Temp = Head;

				Will_Delete = Head;
				Temp = Head;

				while (Temp->Next != Head) { Temp = Temp->Next; }

				Temp->Next = Head->Next;

				delete(Head);

				Head = Temp->Next;
			}
		}
		else {
			CircularLinkedList *Temp = Head;

			for (int i = 2; i < n; i++) {
				if (Temp->Next != Head) {
					Temp = Temp->Next;
				}
				else {
					cout << "Error! You entered Location Greater than Linked List size" << endl;

					return;
				}
			}						
			CircularLinkedList *Will_Delete = Temp->Next;

			Temp->Next = Temp->Next->Next;

			delete(Will_Delete);
		}
	}

	void Print() {
		cout << "Linked List is  : ";

		if (Head != NULL) {
			CircularLinkedList *Temp = Head;

			do {
				cout << Temp->Data << " ";

				Temp = Temp->Next;
			} while (Temp != Head);
		}
		cout << endl;
	}
};

void main() {
	CircularLinkedList Ob;

	Ob.Delete_at_nth(0);
		
	Ob.Insert_at_End(1);
	Ob.Delete_at_nth(1);
	Ob.Print();

	Ob.Insert_at_End(2);
	Ob.Insert_at_End(3);
	Ob.Delete_at_nth(1);
	Ob.Print();

	Ob.Insert_at_End(4);
	Ob.Delete_at_nth(2);
	Ob.Print();

	Ob.Insert_at_End(5);
	Ob.Insert_at_End(6);
	Ob.Insert_at_End(7);
	Ob.Insert_at_End(8);
	Ob.Delete_at_nth(3);
	Ob.Print();

	Ob.Delete_at_nth(3);
	Ob.Print();

	Ob.Delete_at_nth(17);
}

