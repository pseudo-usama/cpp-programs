// Inserting a Node in Linked List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "malloc.h"
using namespace std;

struct Node {
public:
	int Data;
	Node *Next;
};

void main() {
	Node *Head = NULL;

	//First Creating Linked List of Three Nodes
	Node *FirstNode, *SecondNode, *ThirdNode, *temp;

	FirstNode = (Node*)malloc(sizeof(Node));
	SecondNode = (Node*)malloc(sizeof(Node));
	ThirdNode = (Node*)malloc(sizeof(Node));

	Head = FirstNode;

	FirstNode->Data = 10;
	FirstNode->Next = SecondNode;

	SecondNode->Data = 20;
	SecondNode->Next = ThirdNode;

	ThirdNode->Data = 30;
	ThirdNode->Next = NULL;



	//we have now Three Node
	//Now we create a new Node in between the Linked Lists

	Node *NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = 15;
	
	//Now creating Links
	NewNode->Next = FirstNode->Next;
	FirstNode->Next = NewNode;



	//Now Displaying Linked List
	temp = FirstNode;

	cout << "Our Linked List is   : ";
	while (temp != NULL) {
		cout << temp->Data << "  ";

		temp = temp->Next;
	}
	cout << endl;
}

