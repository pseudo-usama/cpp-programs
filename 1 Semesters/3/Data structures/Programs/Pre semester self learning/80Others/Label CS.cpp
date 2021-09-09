// Label CS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "fstream"
using namespace std;

void main() {	
	ofstream Write;
	Write.open("E:\\Label.txt", ios::out);

	for (int i = 2; i < 73; i++) {
		Write << "label";
		Write << i;
		Write << ".Text = Rand.Next(0, 10).ToString(); label";
		Write << i;
		Write << ".Refresh();";

		Write << endl;
	}
}

