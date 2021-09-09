// Successor in BST.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

struct BinaryTree {
	int Data;
	BinaryTree *Left;
	BinaryTree *Right;
};

BinaryTree *Root = NULL;

BinaryTree *Insert_with_Recursion(int _Data, BinaryTree *Current) {
	if (Current == NULL) {
		BinaryTree *NewNodew = new BinaryTree;

		NewNodew->Data = _Data;
		NewNodew->Left = NewNodew->Right = NULL;

		return(NewNodew);
	}
	else if (_Data <= Current->Data) {
		Current->Left = Insert_with_Recursion(_Data, Current->Left);
	}
	else {
		Current->Right = Insert_with_Recursion(_Data, Current->Right);
	}
	return(Current);
}

void Inorder_Traversal(BinaryTree *Current) {
	if (Current != NULL) {
		Inorder_Traversal(Current->Left);

		cout << Current->Data << " ";

		Inorder_Traversal(Current->Right);
	}
}

BinaryTree *Successor(int _Data) {
	if (Root == NULL) { return(NULL); }

	BinaryTree *Current = Root;

	while (_Data != Current->Data && Current != NULL) {
		if (_Data < Current->Data) {
			Current = Current->Left;
		}
		else if (_Data>Current->Data) {
			Current = Current->Right;
		}
	}
	if (Current == NULL) { return(NULL); }

	if (Current->Right != NULL) {
		BinaryTree *Temp = Current->Right;

		while (Temp->Left != NULL) {
			Temp = Temp->Left;
		}
		return(Temp);
	}
	else {
		BinaryTree *Successor = NULL;
		BinaryTree *Ancestor = Root;

		while (Ancestor != Current) {
			if (Current->Data < Ancestor->Data) {
				Successor = Ancestor;
				Ancestor = Ancestor->Left;
			}
			else {
				Ancestor = Ancestor->Right;
			}
		}
		return(Successor);
	}
}

void main() {
	Root = Insert_with_Recursion(10, Root);
	Root = Insert_with_Recursion(1, Root);
	Root = Insert_with_Recursion(0, Root);
	Root = Insert_with_Recursion(-10, Root);
	Root = Insert_with_Recursion(12, Root);
	Root = Insert_with_Recursion(15, Root);
	Root = Insert_with_Recursion(3, Root);
	Root = Insert_with_Recursion(5, Root);
	Root = Insert_with_Recursion(9, Root);

	Inorder_Traversal(Root);

	cout << endl;

	BinaryTree *Address;

	Address = Successor(10);
	cout << Address->Data << endl;

	Address = Successor(0);
	cout << Address->Data << endl;

	Address = Successor(9);
	cout << Address->Data << endl;

	Address = Successor(12);
	cout << Address->Data << endl;

	Address = Successor(15);
	if (Address == NULL) { cout << '0' << endl; }
	else 
	cout << Address->Data << endl;
}

