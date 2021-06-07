// 31) 5-5 ARRAY Double it and show.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

void Display(int n[5][5]) {

	int i = 0, j;

	while (i < 5) {
		j = 0;
		while (j < 5) {

			cout << n[i][j] << " ";
			j++;
		}
		cout << endl;
		i++;
	}
}

void ArrayDouble(int n[5][5]) {

	int i = 0, j;

	while (i < 5) {
		j = 0;
		while (j < 5) {
			n[i][j] *= 2;

			j++;
		}
		i++;
	}
	Display(n);
}

int main()
{
	int n[5][5], i = 0, j;

	while (i < 5) {
		j = 0;
		while (j < 5) {

			cout << "Enter the " << i << "*" << j << "'s index number  = ";
			cin >> n[i][j];
			j++;
		}
		i++;
	}

	cout << endl << "The values before DOUBLING." << endl << endl;
	Display(n);

	cout << endl << "The values after DOUBLING." << endl << endl;
	ArrayDouble(n);

	return 0;
}

