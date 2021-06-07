// Min and Max in Binary Tree.cpp : Defines the entry point for the console application.
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

void Find_Min_with_Loop() {
	if (Root == NULL) { cout << "Binary Tree is empty" << endl; return; }

	BST_Node *Temp = Root;

	while (Temp->Left != NULL) {
			Temp = Temp->Left;
	}
	cout << "Max  : " << Temp->Data << endl;
}

void Find_Min_with_Recursion(BST_Node *Temp) {
	if (Temp == NULL) { cout << "Tree is empty" << endl; return; }

	if (Temp->Left == NULL) {
		cout << "Min  : " << Temp->Data << endl;

		return;
	}
	Find_Min_with_Recursion(Temp->Left);
}

void Find_Max_with_Loop() {
	if (Root == NULL) { cout << "Binary Tree is empty" << endl; return; }

	BST_Node *Temp = Root;

	while (Temp->Right != NULL) {
		Temp = Temp->Right;
	}
	cout << "Max  : " << Temp->Data << endl;
}

void Find_Max_with_Recursion(BST_Node *Temp) {
	if (Temp == NULL) { cout << "Tree is empty" << endl; return; }

	if (Temp->Right == NULL) {
		cout << "Max  : " << Temp->Data << endl;

		return;
	}
	Find_Max_with_Recursion(Temp->Right);
}

void main() {
	Find_Max_with_Loop();
	Find_Min_with_Loop();

	cout << endl;

	Find_Max_with_Recursion(Root);
	Find_Min_with_Recursion(Root);

	cout << endl;

	Root = Insert_with_Recursion(10, Root);
	Root = Insert_with_Recursion(1, Root);
	Root = Insert_with_Recursion(-3, Root);
	Root = Insert_with_Recursion(23, Root);
	Root = Insert_with_Recursion(2, Root);

	Find_Max_with_Loop();
	Find_Min_with_Loop();
	
	cout << endl;

	Find_Max_with_Recursion(Root);
	Find_Min_with_Recursion(Root);
}

