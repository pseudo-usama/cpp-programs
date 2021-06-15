// Inorder Traversal (Binary Tree).cpp : Defines the entry point for the console application.
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

void Inorder_Traversal_with_Recursion(BST *Current) {
	if (Current == NULL) { return; }

	Inorder_Traversal_with_Recursion(Current->Left);

	cout << Current->Data << " ";

	Inorder_Traversal_with_Recursion(Current->Right);
}

void main() {
	cout << "Binary Tree is  : ";
	Inorder_Traversal_with_Recursion(Root);
	cout << endl;

	Root = Insert_with_Recursion(10, Root);
	Root = Insert_with_Recursion(0, Root);
	Root = Insert_with_Recursion(-10, Root);
	Root = Insert_with_Recursion(1, Root);
	Root = Insert_with_Recursion(24, Root);
	Root = Insert_with_Recursion(5, Root);
	Root = Insert_with_Recursion(3, Root);
	Root = Insert_with_Recursion(9, Root);

	cout << "Binary Tree is  : ";
	Inorder_Traversal_with_Recursion(Root);
	cout << endl;
}

