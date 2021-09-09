// Calculate Time.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "ctime"
using namespace std;

void main() {
	int Start = clock();

	for (int i = 0; i < 1000; i++) {
		cout << "a";
	}

	int End = clock();

	cout << "Time for this Program is  : " << (End - Start) / double(CLOCKS_PER_SEC) * 1000 << endl;

}

