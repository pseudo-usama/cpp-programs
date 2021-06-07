// Simple Single Linked List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "malloc.h";
using namespace std;

struct Node {
public:
	int Data;
	Node *Next;
};

void main() {
	Node *Head = NULL;

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

	temp = FirstNode;

	cout << "Our Linked List is   : ";
	while (temp != NULL) {
		cout << temp->Data << "  ";

		temp = temp->Next;
	}
	cout << endl;
}

