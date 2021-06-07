// Stack UsingArray 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

#define MAX 50

int Stack[MAX];
int top = -1;

void Push(int n) {
	if (top < MAX) {
		Stack[++top] = n;
	}
	else {
		cout << "Error! Stack is Full." << endl;
	}
}

void Pop() {
	if (top == -1) {
		cout << "Error! Stack is Empty." << endl;
	}
	else {
		top--;
	}
}

int Top() {
	return(Stack[top]);
}

void Print() {		//This Function is not necessory in implimentation of Stack it is just for checking the Stack
	cout << "Stack is  : ";

	for (int i = 0; i <= top; i++) {
		cout << Stack[i] << " ";
	}
	cout << endl;
}

void main() {
	Pop();

	Push(1);	Print();	//Stack is  : 1 
	Push(2);	Print();	//Stack is  : 1 2 
	Push(3);	Print();	//Stack is  : 1 2 3 
	Push(4);	Print();	//Stack is  : 1 2 3 4 
	Push(5);	Print();	//Stack is  : 1 2 3 4 5 
	Push(6);	Print();	//Stack is  : 1 2 3 4 5 6 
	Push(7);	Print();	//Stack is  : 1 2 3 4 5 6 7 

	Pop();		Print();	//Stack is  : 1 2 3 4 5 6 

	Top();		Print();	//Stack is  : 1 2 3 4 5 6 
	Top();		Print();	//Stack is  : 1 2 3 4 5 6 

	Pop();		Print();	//Stack is  : 1 2 3 4 5 
	Pop();		Print();	//Stack is  : 1 2 3 4 
	Pop();		Print();	//Stack is  : 1 2 3 
	Pop();		Print();	//Stack is  : 1 2 
}

