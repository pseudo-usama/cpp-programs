// Queue using Linked Lists.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

struct Node {
	int Data;
	Node *Next;
};

Node *Front = NULL;
Node *Rear = NULL;

bool Is_Empty() {
	if (Front == NULL) { return(true ); }
	else               { return(false); }
}

void Enqueue(int _Data) {
	Node *Temp = new Node;

	Temp->Data = _Data;
	Temp->Next = NULL;

	if (Rear == NULL) { Front = Rear = Temp; }
	else {
		Rear->Next = Temp;
		Rear = Temp;
	}
}

void Dequeue() {
	if (Is_Empty()) { cout << "Error! Queue is empty." << endl; return; }

	Node *Temp = Front;

	if (Front == Rear) { Front = Rear = NULL; }
	else               { Front = Front->Next; }

	delete Temp;
}

void Front_Fn() {
	if (Front == NULL) {
		cout << "Error! Queue is empty." << endl;
		return;
	}

	Node *Temp = Front;

	cout << "Data is  : " << Temp->Data << endl;
}

void Print() {		//This Print Function is only to see Queue whole Data its not the acctual implementation of Queue
	Node *Temp = Front;

	cout << "Queue is  : ";

	while (Temp != NULL) {
		cout << Temp->Data << " ";
		Temp = Temp->Next;
	}
	cout << endl;
}

void main() {
	Dequeue();		Print();		//Queue is  :		(Error)

	Enqueue(1);		Print();		//Queue is  : 1 
	Enqueue(4);		Print();		//Queue is  : 1 4 

	Front_Fn();		Print();		//Queue is  : 1 4 

	Dequeue();		Print();		//Queue is  : 4 
	Dequeue();		Print();		//Queue is  :
	Dequeue();		Print();		//Queue is  :		(Error)
}

