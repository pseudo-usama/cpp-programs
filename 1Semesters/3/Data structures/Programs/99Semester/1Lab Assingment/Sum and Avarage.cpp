// Sum and Avarage.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

void main() {
	int const L = 10;

	int Array[L] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	int Sum = 0;

	for (int i = 0; i < L; i++) {
		Sum += Array[i];
	}
	cout << "Sum is      : " << Sum << endl;
	cout << "Average is  : " << Sum / L << endl << endl;
}

