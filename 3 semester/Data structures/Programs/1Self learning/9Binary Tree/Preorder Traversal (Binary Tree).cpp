// Preorder Traversal (Binary Tree).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

struct BST {
	int Data;
	BST *Right;
	BST *Left;
};

BST *Root = NULL;

void Insert_with_Loop(int _Data) {
	BST **Temp = &Root;

	BST *NewNode = new BST;
	NewNode->Data = _Data;
	NewNode->Left = NewNode->Right = NULL;

	while (*Temp != NULL) {
		if (_Data <= (**Temp).Data) {
			Temp = &(**Temp).Left;
		}
		else {
			Temp = &(**Temp).Right;
		}
	}
	*Temp = NewNode;
}

void Preorder_Traversal_with_Recursion(BST *Current) {
	if (Current == NULL) { return; }

	cout << Current->Data << " ";

	Preorder_Traversal_with_Recursion(Current->Left);
		
	Preorder_Traversal_with_Recursion(Current->Right);
	
}

void main() {
	cout << "Binary Tree is  : ";
	Preorder_Traversal_with_Recursion(Root);
	cout << endl;

	Insert_with_Loop(10);
	Insert_with_Loop(-1);
	Insert_with_Loop(23);
	Insert_with_Loop(4);
	Insert_with_Loop(5);
	Insert_with_Loop(8);
	Insert_with_Loop(0);

	cout << "Binary Tree is  : ";
	Preorder_Traversal_with_Recursion(Root);
	cout << endl;
}

