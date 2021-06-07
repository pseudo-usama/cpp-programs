// Delerte Node (BST).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

struct BinaryTree {
	int Data;
	BinaryTree *Right;
	BinaryTree *Left;
};

BinaryTree *Root = NULL;

void Insert_with_Loop(int _Data) {
	BinaryTree *NewNode = new BinaryTree;
	NewNode->Data = _Data;
	NewNode->Left = NewNode->Right = NULL;

	BinaryTree **Temp = &Root;

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

void Inorder_Traversal(BinaryTree *Current) {
	if (Current == NULL) { return; }

	Inorder_Traversal(Current->Left);

	cout << Current->Data << " ";

	Inorder_Traversal(Current->Right);
}

int Find_Min(BinaryTree *Current) {
	if (Current->Left == NULL) { return(Current->Data); }
	
	return(Find_Min(Current->Left));
}

BinaryTree *Delete_Node(int _Data, BinaryTree *Current) {
	if (Current == NULL) { return(Current); }

	if (_Data < Current->Data) {
		Current->Left = Delete_Node(_Data, Current->Left);
	}
	else if (_Data > Current->Data) {
		Current->Right = Delete_Node(_Data, Current->Right);
	}
	else {
		if (Current->Left == NULL && Current->Right == NULL) {
			delete(Current);

			Current = NULL;
		}
		else if (Current->Left == NULL) {
			BinaryTree *Temp = Current;
			
			Current = Current->Right;

			delete(Temp);
		}
		else if (Current->Right == NULL) {
			BinaryTree *Temp = Current;

			Current = Current->Left;

			delete(Temp);
		}
		else {
			Current->Data = Find_Min(Current->Right);

			Current->Right = Delete_Node(Current->Data, Current->Right);
		}
	}
	return(Current);
}

void main() {
	Inorder_Traversal(Root);
	cout << endl;

	Insert_with_Loop(10);
	Insert_with_Loop(1);
	Insert_with_Loop(-1);
	Insert_with_Loop(24);
	Insert_with_Loop(8);
	Insert_with_Loop(3);
	Insert_with_Loop(5);
	Insert_with_Loop(-4);
	Insert_with_Loop(30);
	Insert_with_Loop(25);
	Insert_with_Loop(31);
	Insert_with_Loop(0);



	Inorder_Traversal(Root);			//-4 -1 0 1 3 5 8 10 24 25 30 31 
	cout << endl;

	Root = Delete_Node(0, Root);

	Inorder_Traversal(Root);			//-4 -1 1 3 5 8 10 24 25 30 31 
	cout << endl;

	Root = Delete_Node(3, Root);

	Inorder_Traversal(Root);			//-4 -1 1 5 8 10 24 25 30 31 
	cout << endl;

	Root = Delete_Node(8, Root);

	Inorder_Traversal(Root);			//-4 -1 1 5 10 24 25 30 31 
	cout << endl;

	Root = Delete_Node(10, Root);

	Inorder_Traversal(Root);			//-4 -1 1 5 24 25 30 31 
	cout << endl;


}

