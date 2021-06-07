// Char_ a and A CS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "fstream"
using namespace std;

void main() {
	ofstream Write;
	Write.open("E:\\s.txt", ios::out);

	for (int i = 65, j = 97; i < 91; i++, j++) {
		Write << "Char_";
		Write << char(j);
		Write << ".Text = \"";
		Write << char(j);
		Write << "\";";

		Write << endl;
	}
}

