// ahmed puzzle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"iostream"
using namespace std;

void main() {
	int Array[8] = { 1, 3, 5, 7, 9, 11, 13, 15 };

	int a = 0, b = 0, c = 0;

	while (a != 8){
		if (Array[a] + Array[b] + Array[c] == 30){
			cout << Array[a] << " " << Array[b] << " " << Array[c] << endl;

			exit(0);
		}

		c++;
		if (c == 8){
			b++;
			c = 0;
		}
		
		if (b == 8){
			a++;
			b = 0;
		}
	}
	cout << "Solution not found." << endl;
}

