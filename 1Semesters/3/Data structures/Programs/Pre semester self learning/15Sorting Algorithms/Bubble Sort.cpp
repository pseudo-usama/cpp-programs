// Bubble Sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

void Bubble_Sort(int Array[], int n) {
	int Temp;
	bool Sorted;
	n--;

	for (int i = 0; i < n; i++) {
		Sorted = true;

		for (int j = 0; j < n - i; j++) {
			if (Array[j]>Array[j + 1]) {
				Temp = Array[j];
				Array[j] = Array[j + 1];
				Array[j + 1] = Temp;

				Sorted = false;
			}
		}
		if (Sorted) { break; }
	}
}

void main() {
	#define MAX 20

	int Array[MAX] = { 4, 1, 7, 19, 20, 9, 8, 5, 15, 14, 17, 16, 12, 11, 10, 6, 3 ,2, 13, 18};

	cout << "Array before BUBBLE Sort  : ";

	for (int i = 0; i < 20; i++) {
		cout << Array[i] << " ";
	}
	cout << endl;

	Bubble_Sort(Array, MAX);

	cout << "Array after BUBBLE Sort  : ";

	for (int i = 0; i < 20; i++) {
		cout << Array[i] << " ";
	}
	cout << endl;
}

