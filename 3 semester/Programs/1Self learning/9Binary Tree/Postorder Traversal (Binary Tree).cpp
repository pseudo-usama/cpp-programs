// Postorder Traversal (Binary Tree).cpp : Defines the entry point for the console application.
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
	BST *NewNode = new BST;
	NewNode->Data = _Data;
	NewNode->Left = NewNode->Right = NULL;

	BST **Temp = &Root;

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

void PostOrder_Traversal_with_Recursion(BST *Current) {
	if (Current == NULL) { return; }

	PostOrder_Traversal_with_Recursion(Current->Left);

	PostOrder_Traversal_with_Recursion(Current->Right);

	cout << Current->Data << " ";
}

void main() {
	cout << "Binary Tree is  ";
	PostOrder_Traversal_with_Recursion(Root);
	cout << endl;

	Insert_with_Loop(10);
	Insert_with_Loop(1);
	Insert_with_Loop(4);
	Insert_with_Loop(3);
	Insert_with_Loop(9);
	Insert_with_Loop(-10);
	Insert_with_Loop(0);
	Insert_with_Loop(23);
	Insert_with_Loop(25);
	Insert_with_Loop(22);

	cout << "Binary Tree is  ";
	PostOrder_Traversal_with_Recursion(Root);
	cout << endl;
}

