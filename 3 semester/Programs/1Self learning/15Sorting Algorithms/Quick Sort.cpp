// Quick Sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

inline void Swap(int &a, int &b) {
	int Temp = a;
	a = b;
	b = Temp;
}

int Partition(int Array[], int Start, int End) {
	int Pivot = Array[End];
	int PartitionIndex = Start /*Start + (rand() % (End - Start))*/;

	for (int i = Start; i < End; i++) {
		if (Array[i] <= Pivot) {
			Swap(Array[i], Array[PartitionIndex++]);
		}
	}
	Swap(Array[PartitionIndex], Array[End]);

	return(PartitionIndex);
}

void Quick_Sort(int Array[], int Start, int End) {
	if (Start < End) {
		int Pivot = Partition(Array, Start, End);

		Quick_Sort(Array, Start, Pivot - 1);
		Quick_Sort(Array, Pivot + 1, End);
	}
}

void main() {
	#define MAX 20

	int Array[MAX] = { 4, 1, 7, 19, 20, 9, 8, 5, 15, 14, 17, 16, 12, 11, 10, 6, 3, 2, 13, 18 };

	cout << "Array before QUICK Sort  : ";

	for (int i = 0; i < 20; i++) {
		cout << Array[i] << " ";
	}
	cout << endl;

	Quick_Sort(Array, 0, MAX - 1);

	cout << "Array after QUICK Sort  : ";

	for (int i = 0; i < 20; i++) {
		cout << Array[i] << " ";
	}
	cout << endl;
}

