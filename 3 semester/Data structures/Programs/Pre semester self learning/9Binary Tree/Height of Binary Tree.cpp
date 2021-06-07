// Height of Binary Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int Max_Number(int a, int b) {
	if (a > b) {
		return(a);
	}
	else {
		return(b);
	}
}

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

	while (true) {
		if (*Temp == NULL) {
			*Temp = NewNode;

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

int Height_with_Recursion(BST *Temp) {
	if (Temp == NULL) {
		return(-1);
	}
	return( Max_Number(Height_with_Recursion(Temp->Left), Height_with_Recursion(Temp->Right)) + 1 );
}

void main() {
	Insert_with_Loop(10);
	Insert_with_Loop(1);
	Insert_with_Loop(-1);
	Insert_with_Loop(4);
	Insert_with_Loop(5);
	Insert_with_Loop(23);

	cout << "Height of Binary Tree is  : " << Height_with_Recursion(Root) << endl << endl;
}

