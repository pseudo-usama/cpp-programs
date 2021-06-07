// Shell Sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

void Swap(int &a, int &b) {
	int Temp = a;
	a = b;
	b = Temp;
}

void Shell_Sort(int Array[], int n) {

	for (int Gap = n / 2; Gap > 0; Gap /= 2) {
		for (int i = 0; i + Gap < n; i++) {
			if (Array[i] > Array[i + Gap]) {
				Swap(Array[i], Array[Gap + i]);

				for (int j = i; j > 0 && Array[j] < Array[j - 1]; j--) {
						Swap(Array[j], Array[j - 1]);
				}
			}
		}		
	}
}

void main() {
	#define MAX 20

	int Array[MAX] = { 4, 1, 7, 19, 20, 9, 8, 5, 15, 14, 17, 16, 12, 11, 10, 6, 3, 2, 13, 18 };

	cout << "Array before SHELL Sort  : ";

	for (int i = 0; i < 20; i++) {
		cout << Array[i] << " ";
	}
	cout << endl;

	Shell_Sort(Array, MAX);

	cout << "Array after SHELL Sort  : ";

	for (int i = 0; i < 20; i++) {
		cout << Array[i] << " ";
	}
	cout << endl;
}

