// Inverse Links by Recursive.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

struct Node {
	int Data;
	Node *Next;
};

Node *Head;

void Print(Node *Temp) {
	if (Temp == NULL) { return; }

	cout << Temp->Data << " ";

	Print(Temp->Next);		
}

void Reverce_Links_by_Recursive_Method(Node *Temp, Node *Temp2) {	//My Method
	if (Temp2 == NULL) { 
		Head->Next = NULL;
		Head = Temp;

		return;
	}

	Reverce_Links_by_Recursive_Method(Temp->Next, Temp2->Next);

	Temp2->Next = Temp;
}

void Reverce_Links_by_Recursive_Method(Node *Temp2) {		//Video Tutorial Method
	if (Temp2->Next == NULL) {
		Head = Temp2;
		return;
	}
	Reverce_Links_by_Recursive_Method(Temp2->Next);

	/*Node *Temp = Temp2->Next;
	Temp->Next = Temp2;*/				//Insted  of using these two lines we also use the below line

	Temp2->Next->Next = Temp2;			//This line and upper two lines are alternative

	Temp2->Next = NULL;
}

void main() {
	Head = NULL;

	for (int i = 10; i > 0; i--) {
		Node *Temp = new Node;

		Temp->Data = i;

		Temp->Next = Head;
		Head = Temp;
	}
	cout << "List is  : ";
	Print(Head);
	cout << endl;
	
	Reverce_Links_by_Recursive_Method(Head);

	cout << "List is  : ";
	Print(Head);
	cout << endl;
}

