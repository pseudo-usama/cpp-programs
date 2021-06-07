// Preshtalwalker Puzzle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main() {
	int Blue = 0, Grey = 0, Red = 0, temp = 0;
	
	while( Red<10 ) {
		if (Blue != Grey && Blue != Red && Grey != Red) {
			temp = Blue * 100 + Grey * 10 + Red;

			temp *= 3;

			if (temp / 100 == Red && (temp / 10) % 10 == Red && temp % 10 == Red) {
				cout << "Blue is   = " << Blue << endl;
				cout << "Grey is   = " << Grey << endl;
				cout << "Red is    = " << Red << endl;

				system("pause");
				exit(0);
			}
		}

		Blue++;

		if (Blue == 10) { Grey++; Blue = 0; }
		
		if (Grey == 10) { Red++; Grey = 0; }
		
	}
	
	cout << "Sorry Numbers not found Checking range [000, 999]" << endl << endl;
	system("pause");

	return 0;
}

