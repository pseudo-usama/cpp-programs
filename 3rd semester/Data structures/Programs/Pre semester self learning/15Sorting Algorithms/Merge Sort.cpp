// Merge Sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

#define MAX 20

int Array[MAX] = { 4, 18, 7, 19, 20, 9, 8, 5, 15, 14, 17, 16, 12, 11, 10, 6, 3, 2, 13, 1 };
int Temp[MAX - 1];

void Merging(int Min, int Mid, int Max) {
	int L1 = Min, L2 = Mid + 1, i;

	for (i = Min; L1 <= Mid && L2 <= Max; i++) {
		if (Array[L1] <= Array[L2]) {
			Temp[i] = Array[L1++];
		}
		else {
			Temp[i] = Array[L2++];
		}
	}
	while (L1 <= Mid) {
		Temp[i++] = Array[L1++];
	}
	while (L2 <= Max) {
		Temp[i++] = Array[L2++];
	}

	for (i = Min; i <= Max; i++) {
		Array[i] = Temp[i];
	}
}

void Sort(int Min, int Max) {
	if (Min < Max) {
		int Mid = (Min + Max) / 2;

		Sort(Min, Mid);
		Sort(Mid + 1, Max);

		Merging(Min, Mid, Max);
	}
}

void main() {

	cout << "Array before MERGE Sort  : ";

	for (int i = 0; i < 20; i++) {
		cout << Array[i] << " ";
	}
	cout << endl;

	Sort(0, MAX);

	cout << "Array after MERGE Sort  : ";

	for (int i = 0; i < 20; i++) {
		cout << Array[i] << " ";
	}
	cout << endl;
}

