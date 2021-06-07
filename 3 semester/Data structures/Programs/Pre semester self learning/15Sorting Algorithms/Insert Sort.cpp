// Insert Sort.cpp : Defines the entry point for the console application.
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

void Insert_Sort(int Array[], int n) {

	for (int i = 0; i < n - 1; i++) {

		if (Array[i] > Array[i + 1]) {

			Swap(Array[i], Array[i + 1]);

			for (int j = i; j > 0 && Array[j] < Array[j - 1]; j--) {

				Swap(Array[j], Array[j - 1]);				
			}
		}
	}
}

void main() {
	#define MAX 20

	int Array[MAX] = { 4, 18, 7, 19, 20, 9, 8, 5, 15, 14, 17, 16, 12, 11, 10, 6, 3, 2, 13, 1 };

	cout << "Array before INSERT Sort  : ";

	for (int i = 0; i < 20; i++) {
		cout << Array[i] << " ";
	}
	cout << endl;

	Insert_Sort(Array, MAX);

	cout << "Array after INSERT Sort  : ";

	for (int i = 0; i < 20; i++) {
		cout << Array[i] << " ";
	}
	cout << endl;
}

