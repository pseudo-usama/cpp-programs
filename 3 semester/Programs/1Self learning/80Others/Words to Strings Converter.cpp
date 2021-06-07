// Words to Strings Converter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "string"
#include "queue"
using namespace std;

void main() {
	ifstream Read;
	Read.open("E:\\Words.txt", ios::in);

	string String, Result="\0";
	queue<char> Queue;

	int Length;

	while (!Read.eof()) {
		Read >> String;

		Length = String.length();

		for (int i = 0; i < Length; i++) {
			Queue.push(String[i]);
		}

		Result += "\"";

		for (int i = 0; i < Length; i++) {
			Result += Queue.front();
			Queue.pop();
		}
		Result += "\", ";
	}

	ofstream Write;
	Write.open("E:\\Words in string.txt");

	Write << Result;
}

