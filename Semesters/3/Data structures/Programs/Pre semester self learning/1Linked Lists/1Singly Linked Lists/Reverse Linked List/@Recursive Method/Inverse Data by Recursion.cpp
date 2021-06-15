// Inverse Data by Recursion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

struct Node {
	int Data;
	Node *Next;
};

Node *Head;
int Length_Linked_List = 0;
int Swpping_Times = 0;

void Print() {
	Node *Temp = Head;

	cout << "List is  : ";

	while (Temp != NULL) {
		cout << Temp->Data << " ";

		Temp = Temp->Next;
	}
	cout << endl;
}

Node *Reverse_Data_of_Linked_List_by_Recursive_Calling(Node *Temp2) {
	if (Temp2 == NULL) {

		return(Head);
	}
	Length_Linked_List++;

	Node *Temp = Reverse_Data_of_Linked_List_by_Recursive_Calling(Temp2->Next);

	if (Swpping_Times <= Length_Linked_List / 2) {
		int Swaper;

		Swaper = Temp2->Data;
		Temp2->Data = Temp->Data;
		Temp->Data = Swaper;

		Swpping_Times++;
	}
	return(Temp->Next);
}

void main() {
	Head = NULL;

	for (int i = 11; i > 0; i--) {
		Node *Temp = new Node;

		Temp->Data = i;

		Temp->Next = Head;
		Head = Temp;
	}
	Print();

	Reverse_Data_of_Linked_List_by_Recursive_Calling(Head);

	Print();
}

