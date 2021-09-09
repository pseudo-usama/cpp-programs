// Deleting Node in Linked List.cpp : Defines the entry point for the console application.
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
	Node *FirstNode, *SecondNode, *ThirdNode, *ForthNode, *temp;

	FirstNode = (Node*)malloc(sizeof(Node));
	SecondNode = (Node*)malloc(sizeof(Node));
	ThirdNode = (Node*)malloc(sizeof(Node));
	ForthNode = (Node*)malloc(sizeof(Node));

	Head = FirstNode;

	FirstNode->Data = 10;
	FirstNode->Next = SecondNode;

	SecondNode->Data = 15;
	SecondNode->Next = ThirdNode;

	ThirdNode->Data = 20;
	ThirdNode->Next = ForthNode;


	ForthNode->Data = 30;
	ForthNode->Next = NULL;


	//Now we Delete the third Node cointaining 20

	//Changing Link
	SecondNode->Next = ForthNode;

	//Now Deleting Third Node
	free(ThirdNode);



	//Now Displaying Linked List
	temp = FirstNode;

	cout << "Our Linked List is   : ";
	while (temp != NULL) {
		cout << temp->Data << "  ";

		temp = temp->Next;
	}
	cout << endl;
}

