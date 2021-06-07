// Selection Sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

void inline Swap(int &a, int &b) {
	int Temp;

	Temp = a;
	a = b;
	b = Temp;
}

int Find_Min(int Array[], int Size, int i/*Start Position*/) {
	int Min = Array[i];
	int Index = i;

	for (i++ ; i < Size; i++) {
		if (Array[i] < Min) {
			Min = Array[i];
			Index = i;
		}
	}
	return(Index);
}

void Selection_Sort(int Array[], int n) {
	int Index;

	for (int i = 0; i < n - 1; i++) {
		Index = Find_Min(Array, n, i);

		if (Array[Index] < Array[i]) {
			Swap(Array[Index], Array[i]);
		}
	}
}

void main() {
	#define MAX 20

	int Array[MAX] = { 4, 18, 7, 19, 20, 9, 8, 5, 15, 14, 17, 16, 12, 11, 10, 6, 3, 2, 13, 1 };

	cout << "Array before SELECTION Sort  : ";

	for (int i = 0; i < 20; i++) {
		cout << Array[i] << " ";
	}
	cout << endl;

	Selection_Sort(Array, MAX);

	cout << "Array after SELECTION Sort  : ";
	
	for (int i = 0; i < 20; i++) {
		cout << Array[i] << " ";
	}
	cout << endl;
}

