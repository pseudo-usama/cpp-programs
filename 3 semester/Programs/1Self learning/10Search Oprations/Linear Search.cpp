// Linear Search.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

#define MAX 20

int Array[MAX] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };

int Linear_Search(int Data) {
	int Index = -1;

	for (int i = 0; i < MAX; i++) {
		if (Array[i] == Data) {
			Index = i;
			break;
		}
	}
	return(Index);
}

void main() {
	int Data, Index;

	cout << "Enter Data to Search     = ";
	cin >> Data;

	Index = Linear_Search(Data);

	if (Index == -1) {
		cout << "Sorry! Data not found." << endl;
	}
	else {
		cout << "Data found at Index no. " << Index << "." << endl;
	}
}

