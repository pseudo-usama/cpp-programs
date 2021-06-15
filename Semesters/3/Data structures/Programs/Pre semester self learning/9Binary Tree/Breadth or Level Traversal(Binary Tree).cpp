// Breadth or Level Traversal(Binary Tree).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "queue"
using namespace std;

struct BST {
	int Data;
	BST *Right;
	BST *Left;
};

BST *Root = NULL;

BST *Insert_with_Recursion(int _Data, BST *Temp) {
	if (Temp == NULL) {
		BST *NewNode = new BST;
		NewNode->Data = _Data;
		NewNode->Left = NewNode->Right = NULL;
		Temp = NewNode;
	}
	else if (_Data <= Temp->Data) {
		Temp->Left = Insert_with_Recursion(_Data, Temp->Left);
	}
	else {
		Temp->Right = Insert_with_Recursion(_Data, Temp->Right);
	}
	return(Temp);
}

void Breadth_Traversal() {
	cout << "The Breadth or Level order of Binary Tree is  : ";

	if (Root == NULL) { cout << endl; return; }

	queue<BST*> Ob;
	BST *Current = Root;

	Ob.push(Current);

	while (!Ob.empty()) {
		Current = Ob.front();
		cout << Current->Data << " ";
		Ob.pop();

		if (Current->Left != NULL) {
			Ob.push(Current->Left);
		}
		if (Current->Right != NULL) {
			Ob.push(Current->Right);
		}
	}
	cout << endl;
}

void main() {
	Breadth_Traversal();

	Root = Insert_with_Recursion(10, Root);
	Root = Insert_with_Recursion(1, Root);
	Root = Insert_with_Recursion(11, Root);
	Root = Insert_with_Recursion(-1, Root);
	Root = Insert_with_Recursion(9, Root);
	Root = Insert_with_Recursion(24, Root);

	Breadth_Traversal();
}

