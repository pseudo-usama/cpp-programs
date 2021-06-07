// Doubly Circular Linked List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

class CircularDoublyLinkedList {
private:
	int Data;
	CircularDoublyLinkedList *Next;
	CircularDoublyLinkedList *Prev;

	CircularDoublyLinkedList *Head = NULL;

public:
	void Insert_at_Start(int _Data) {
		CircularDoublyLinkedList *NewNode = new CircularDoublyLinkedList;
		NewNode->Data = _Data;

		if (Head == NULL) {
			Head = NewNode;
			NewNode->Next = NewNode->Prev = NewNode;
		}
		else {
			NewNode->Next = Head;
			NewNode->Prev = Head->Prev;

			Head->Prev->Next = NewNode;
			Head->Prev = NewNode;

			Head = NewNode;
		}
	}
	void Insert_at_End(int _Data) {
		CircularDoublyLinkedList *NewNode = new CircularDoublyLinkedList;

		NewNode->Data = _Data;

		if (Head == NULL) {
			Head = NewNode;
			NewNode->Next = NewNode->Prev = NewNode;
		}
		else {
			NewNode->Prev = Head->Prev;
			Head->Prev->Next = NewNode;

			NewNode->Next = Head;
			Head->Prev = NewNode;
		}
	}
	void Insert_at_nth(int _Data, int n) {
		if (n < 1) { cout << "Error! Enter a Location Greater then 0." << endl; return; }

		if (Head == NULL && n>1) {
			cout << "Error! Entered Location is greater then Circular Linked List Lenght" << endl;

			return;
		}

		CircularDoublyLinkedList *NewNode = new CircularDoublyLinkedList;
		NewNode->Data = _Data;

		if (n == 1) {
			if (Head == NULL) {
				Head = NewNode;
				NewNode->Next = NewNode->Prev = NewNode;
			}
			else {
				NewNode->Next = Head;
				NewNode->Prev = Head->Prev;

				Head->Prev->Next = NewNode;
				Head->Prev->Prev = NewNode;

				Head = NewNode;
			}
		}
		else {
			CircularDoublyLinkedList *Temp = Head;

			for (int i = 2; i < n; i++) {
				if (Temp->Next != Head) {
					Temp = Temp->Next;
				}
				else {
					cout << "Error! Entered Location is greater then Circular Linked List Lenght" << endl;

					return;
				}
			}
			NewNode->Next = Temp->Next;
			NewNode->Prev = Temp->Next->Prev;

			Temp->Next->Prev = NewNode;
			Temp->Next = NewNode;
		}
	}

	void Delete_at_Start() {
		if (Head == NULL) { cout << "Error! Circular Linked List is Empty." << endl; }

		if (Head->Next == Head) {
			delete(Head);

			Head = NULL;
		}
		else {
			CircularDoublyLinkedList *Temp = Head;

			Temp = Head->Prev;

			Temp->Next = Head->Next;
			Head->Next->Prev = Temp;

			delete(Head);

			Head = Temp->Next;
		}
	}
	void Delete_at_End() {
		if (Head == NULL) { cout << "Error! Doubly Circular Linked List is Empty." << endl; return; }

		if (Head->Next == Head) {
			delete(Head);

			Head = NULL;
		}
		else {
			CircularDoublyLinkedList *Will_Delete = Head->Prev;
			CircularDoublyLinkedList *Temp = Head;

			Temp = Temp->Prev->Prev;

			Temp->Next = Head;
			Head->Prev = Temp;

			delete(Will_Delete);
		}
	}
	void Delete_at_nth(int n) {
		if (Head == NULL) { cout << "Error! Doubly Linked List is Empty." << endl; return; }

		CircularDoublyLinkedList *Temp = Head;

		if (n == 1 && Head->Next == Head) {
			delete(Head);

			Head = NULL;
		}
		else {
			for (int i = 2; i < n; i++) {
				if (Temp->Next != Head) {
					Temp = Temp->Next;
				}
				else {
					cout << "Error! You entered Location Greater then Doubly Circular Linked List Length." << endl;

					return;
				}
			}
			CircularDoublyLinkedList *Will_Delete = Temp->Next;

			Temp->Next = Will_Delete->Next;

			Temp = Will_Delete->Next;

			Temp->Prev = Will_Delete->Prev;

			delete(Will_Delete);
		}
	}

	void Print() {
		cout << "Circular Doubly Linked List is  : ";

		if (Head != NULL) {
			CircularDoublyLinkedList *Temp = Head;

			do {
				cout << Temp->Data << " ";

				Temp = Temp->Next;
			} while (Temp != Head);
		}
		cout << endl;
	}
};

void main() {
	CircularDoublyLinkedList Ob;

	Ob.Print();

	Ob.Insert_at_End(1);
	Ob.Print();

	Ob.Delete_at_nth(1);
	Ob.Print();
	
	Ob.Insert_at_End(2);
	Ob.Insert_at_End(3);
	Ob.Insert_at_End(8);
	Ob.Print();

	Ob.Delete_at_nth(1);
	Ob.Print();

	Ob.Insert_at_End(4);
	Ob.Insert_at_End(5);
	Ob.Insert_at_End(6);
	Ob.Print();

	Ob.Delete_at_nth(2);

	Ob.Print();
}
