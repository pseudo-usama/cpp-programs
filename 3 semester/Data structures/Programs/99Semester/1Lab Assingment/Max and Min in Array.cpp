// Max and Min in Array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

void main() {
	int const L = 10;

	int Array[L] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	int Max = Array[0], Min = Array[0];

	for (int i = 0; i < L; i++) {
		if (Array[i] < Min)
			Min = Array[i];

		if (Array[i] > Max)
			Max = Array[i];
	}
	cout << "Max   : " << Max << endl;
	cout << "Min   : " << Min << endl << endl;
}

