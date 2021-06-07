// Heap Sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

void Heap_Sort(int Array[], int n) {
	
}

void main() {
#define MAX 20

	int Array[MAX] = { 4, 1, 7, 19, 20, 9, 8, 5, 15, 14, 17, 16, 12, 11, 10, 6, 3, 2, 13, 18 };

	cout << "Array before HEAP Sort  : ";

	for (int i = 0; i < 20; i++) {
		cout << Array[i] << " ";
	}
	cout << endl;

	Heap_Sort(Array, MAX);

	cout << "Array after HEAP Sort  : ";

	for (int i = 0; i < 20; i++) {
		cout << Array[i] << " ";
	}
	cout << endl;
}

