// Reverse by Swaping values.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

struct Node {
	int Data;
	Node *Next;
};

Node *Head;

void Print() {
	Node *Temp = Head;

	cout << "List is  : ";

	while (Temp != NULL) {
		cout << Temp->Data << " ";

		Temp = Temp->Next;
	}
	cout << endl;
}

void Invert_Linked_List_Recursion_Method() {
	if (Head != NULL) {
		Node *Last = Head, *First = Head;
		int L = 1;

		while (Last->Next != NULL) {
			Last = Last->Next;
			L++;
		}

		int Swaper;

		Swaper = Last->Data;
		Last->Data = First->Data;
		First->Data = Swaper;

		for (int i = 1; i < L / 2; i++) {
			Last = Head;
			First = First->Next;
			for (int j = 1; j < L - i; j++) {
				Last = Last->Next;
			}
			Swaper = Last->Data;
			Last->Data = First->Data;
			First->Data = Swaper;
		}
	}
}

void main() {
	Head = NULL;

	for (int i = 10; i > 0; i--) {
		Node *Temp = new Node;

		Temp->Data = i;
		Temp->Next = Head;
		Head = Temp;
	}
	Print();

	Invert_Linked_List_Recursion_Method();

	Print();
}

