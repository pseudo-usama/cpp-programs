// text to secret COnverter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "string"
using namespace std;

void Read();
void Write();

void main() {

}

void Read() {
	ifstream Read;
	Read.open("E:\\asd.txt", ios::in);

	ofstream write;
	write.open("E:\\dsa.txt", ios::out);

	string file;
	char a;

	while (!Read.eof()) {
		getline(Read, file);

		for (int i = 0; i < file.length(); i++) {
			write << int(file[i]) << endl;
		}
		write << 128 << endl;
	}
}

void Write() {
	ifstream Read;
	Read.open("E:\\dsa.txt", ios::in);

	ofstream write;
	write.open("E:\\as.txt", ios::out);

	int n;

	while (!Read.eof()) {
		Read >> n;
		
		if (n != 128)
			write << char(n);
		else
			write << endl;
	}
}