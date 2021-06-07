// Binary Search.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

#define MAX 20

int Array[MAX] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };

int Binary_Search(int Data) {
	int Index = -1;
	int Min = 0, Mid, Max = MAX - 1;
	
	while (Min <= Max) {
		Mid = Min + (Max - Min) / 2;

		if      (Array[Mid] == Data) { Index = Mid; break; }
		else if (Array[Mid] > Data)  { Max = Mid - 1;      }
		else                         { Min = Mid + 1;      }
	}
	return(Index);
}

void main() {
	int Data, Index;

	cout << "Enter Data to search     = ";
	cin >> Data;

	Index = Binary_Search(Data);

	if (Index == -1) {
		cout << "Sorry! Data not found" << endl;
	}
	else {
		cout << "Data found at Index no. " << Index << "." << endl;
	}
}

