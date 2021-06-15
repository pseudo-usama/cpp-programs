// Interpolation Search.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include  "iostream"
using namespace std;

#define MAX 30

int Array[MAX] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29 };

int Interpolation_Search(int Data) {
	int Min = 0, Mid, Max = MAX - 1;
	int Iterations = 0;

	while (Min <= Max) {
		Mid = Min + (double(Max - Min) / (Array[Max] - Array[Min])) * (Data - Array[Min]);
				
		if      (Data == Array[Mid]) { return(Mid); break; }
		else if (Data < Array[Mid] ) { Max = Mid - 1;      }
		else                         { Min = Mid + 1;      }

		cout << ++Iterations;
	}
	return(-1);
}

void main() {
	int Data, Index;

	cout << "Enter Data to Search    = ";
	cin >> Data;

	Index = Interpolation_Search(Data);

	if (Index == -1) {
		cout << "Sorry! We could not found any Data" << endl;
	}
	else {
		cout << "Data found at Index no. " << Index << "." << endl;
	}
}

