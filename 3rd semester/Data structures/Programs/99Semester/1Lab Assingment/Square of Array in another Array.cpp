// Square of Array in another Array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

void main() {
	int Array[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int Square[10];

	cout << "Final Squared Array is   : ";

	for (int i = 0; i < 10; i++) {
		Square[i] = Array[i] * Array[i];

		cout << Square[i] << ", ";
	}
	cout << endl;
}

