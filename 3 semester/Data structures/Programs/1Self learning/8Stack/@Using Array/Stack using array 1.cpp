// Stack using array 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "conio.h"
using namespace std;

const int n = 10;
int Stack[n];
int Top = -1;

bool Is_Full() {
	if (Top == n) { return(true); }

	return(false);
}

bool Is_Empty() {
	if (Top == -1) { return(true); }

	return(false);
}

void Push(int Data) {
	if (Is_Full()) { cout << "Error.! Stack is Full" << endl; }
	else {
		Top++;

		Stack[Top] = Data;

		cout << endl << "Stored Successfully" << endl;
	}
}

void Pop() {
	if (Is_Empty()) { cout << "Error.! Stack is Empty." << endl; }
	else {
		cout << "The Data is  = " << Stack[Top] << endl;

		Top--;
	}
}

void main() {
	do{
		int Selector;

		cout << endl << endl;

		cout << "To Push ------------ 1" << endl;
		cout << "To Pop  ------------ 2" << endl;
		cout << "To Exit ------------ 0" << endl << endl;

		cout << "Enter here  ---> ";
		cin >> Selector;

		if (Selector == 1) {
			int Data;

			cout << endl << "Enter Data to save    = ";
			cin >> Data;

			Push(Data);
		}
		else if (Selector == 2) { Pop(); }
		else if (Selector == 0) { exit(0); }

	} while (true);

}


