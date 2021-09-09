// Search Tre Chcking(Min Max).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "queue"
using namespace std;

struct BinaryTree {
	int Data;
	BinaryTree *Right;
	BinaryTree *Left;
};

BinaryTree *Sorted_Root = NULL;
BinaryTree *Unsorted_Root = NULL;

BinaryTree *Insert_with_Recursion_Sorted(int _Data, BinaryTree *Temp) {
	if (Temp == NULL) {
		BinaryTree *NewNode = new BinaryTree;

		NewNode->Data = _Data;
		NewNode->Left = NewNode->Right = NULL;

		Temp = NewNode;
	}
	else if (_Data <= Temp->Data) {
		Temp->Left = Insert_with_Recursion_Sorted(_Data, Temp->Left);
	}
	else {
		Temp->Right = Insert_with_Recursion_Sorted(_Data, Temp->Right);
	}
	return(Temp);
}

void Insert_Unsorted(int _Data) {
	BinaryTree *Temp = Unsorted_Root;

	BinaryTree *NewNode = new BinaryTree;
	NewNode->Data = _Data;
	NewNode->Left = NewNode->Right = NULL;

	if (Unsorted_Root == NULL) {
		Unsorted_Root = NewNode;

		return;
	}

	static int Decider = 0;

	if (Decider % 2) {
		while (Temp->Left != NULL) {
			Temp = Temp->Left;
		}
		Temp->Left = NewNode;
	}
	else {
		while (Temp->Right != NULL) {
			Temp = Temp->Right;
		}
		Temp->Right = NewNode;
	}
}

bool Check_Tree_with_Min_Max(BinaryTree *Current, int Min, int Max) {
	if (Current == NULL) { return(true); }

	if (Current->Data >= Min && Current->Data < Max
		&& Check_Tree_with_Min_Max(Current->Left, Min, Current->Data)
		&& Check_Tree_with_Min_Max(Current->Right, Current->Data, Max))
	{
		return(true);
	}
	else { return(false); }
}

bool Is_Binary_Search_Tree(BinaryTree *Current) {
	return(Check_Tree_with_Min_Max(Current, INT_MIN, INT_MAX));
}

void main() {
	cout << Is_Binary_Search_Tree(Sorted_Root) << endl;

	Sorted_Root = Insert_with_Recursion_Sorted(10, Sorted_Root);
	Sorted_Root = Insert_with_Recursion_Sorted(1, Sorted_Root);
	Sorted_Root = Insert_with_Recursion_Sorted(-1, Sorted_Root);
	Sorted_Root = Insert_with_Recursion_Sorted(25, Sorted_Root);
	Sorted_Root = Insert_with_Recursion_Sorted(5, Sorted_Root);
	Sorted_Root = Insert_with_Recursion_Sorted(3, Sorted_Root);
	Sorted_Root = Insert_with_Recursion_Sorted(11, Sorted_Root);

	cout << Is_Binary_Search_Tree(Sorted_Root) << endl << endl;


	cout << Is_Binary_Search_Tree(Unsorted_Root) << endl;

	Insert_Unsorted(10);
	Insert_Unsorted(1);
	Insert_Unsorted(0);
	Insert_Unsorted(3);
	Insert_Unsorted(-7);
	Insert_Unsorted(24);
	Insert_Unsorted(11);
	Insert_Unsorted(22);

	cout << Is_Binary_Search_Tree(Unsorted_Root) << endl;
}
