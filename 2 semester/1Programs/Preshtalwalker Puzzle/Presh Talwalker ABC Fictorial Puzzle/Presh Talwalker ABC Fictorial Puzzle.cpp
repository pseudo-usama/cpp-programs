// Presh Talwalker ABC Fictorial Puzzle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int Fictorial(int n) {
	if (n != 0) {
		for (int i = n - 1; i != 0; i--) {
			n *= i;
		}
		return(n);
	}
	else {
		return(1);
	}
}

void main() {
	int A = 0, B = 0, C = 0;

	while (A != 10) {
		if (A != B && B != C && A != C) {
			if (A * 100 + B * 10 + C == Fictorial(A) + Fictorial(B) + Fictorial(C)) {
				cout << "Numbers Found!" << endl;
				cout << "A  = " << A << endl;
				cout << "B  = " << B << endl;
				cout << "C  = " << C << endl;
				
				exit(0);
			}
		}
		C++;
		if (C == 10) {
			B++;
			C = 0;

			if (B == 10) {
				A++;
				B = 0;
			}
		}	
	}
	cout << "Sorry! Nubers not found" << endl;
}

