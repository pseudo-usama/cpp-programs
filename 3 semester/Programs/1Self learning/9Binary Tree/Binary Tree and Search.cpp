// Binary Tree and Search.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

struct BST_Node {
	int Data;
	BST_Node *Right;
	BST_Node *Left;
};

BST_Node *Root = NULL;

BST_Node *Insert_with_Recursion(int _Data, BST_Node *Temp) {
	if (Temp == NULL) {
		BST_Node *NewNode = new BST_Node;

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

void Insert_with_Loop(int _Data) {
	BST_Node *NewBST_Node = new BST_Node;

	NewBST_Node->Data = _Data;
	NewBST_Node->Left = NewBST_Node->Right = NULL;

	BST_Node **Temp = &Root;

	while (true) {
		if (*Temp == NULL) {
			*Temp = NewBST_Node;

			break;
		}
		else if (_Data <= (**Temp).Data) {
			Temp = &(**Temp).Left;
		}
		else {
			Temp = &(**Temp).Right;
		}
	}
}

bool Search_with_Recursion(int _Data, BST_Node *Temp) {
	if (Temp == NULL) {
		return(false);
	}
	else if (_Data == Temp->Data) {
		return(true);
	}
	else if (_Data < Temp->Data) {
		return(Search_with_Recursion(_Data, Temp->Left));
	}
	else {
		return(Search_with_Recursion(_Data, Temp->Right));
	}
}

bool Search_with_Loop(int _Data) {
	BST_Node *Temp = Root;

	while (true) {
		if (Temp == NULL) {
			return(false);
		}
		else if (_Data == Temp->Data) {
			return(true);
		}
		else if (_Data < Temp->Data) {
			Temp = Temp->Left;
		}
		else {
			Temp = Temp->Right;
		}
	}
}

void main() {
	Root = Insert_with_Recursion(10, Root);
	Root = Insert_with_Recursion(1, Root);
	Root = Insert_with_Recursion(11, Root);

	Insert_with_Loop(4);
	Insert_with_Loop(7);
	Insert_with_Loop(9);

	cout << Search_with_Recursion(1, Root) << endl;
	cout << Search_with_Recursion(10, Root) << endl;

	cout << Search_with_Loop(4) << endl;
	cout << Search_with_Loop(0) << endl;
}

