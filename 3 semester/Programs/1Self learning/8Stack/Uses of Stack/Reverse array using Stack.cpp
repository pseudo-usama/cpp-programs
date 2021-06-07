// Reverse Str using Stack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "stack"
#include "string"
using namespace std;

string Reverse_Str_using_Built_in_Stack_class(string Str) {
	if (Str[0] == '\0') { return(Str); }

	stack<char> ob;

	for (int i = 0; Str[i] != '\0'; i++) {
		ob.push(Str[i]);
	}

	for (int i = 0; true; ) {
		Str[i] = ob.top();
		ob.pop();

		if (Str[++i] == '\0') { break; }
	}
	return(Str);
}

void  main() {
	string Str;

	cout << "Enter String to invert   = ";
	getline(cin, Str);
	
	Str = Reverse_Str_using_Built_in_Stack_class(Str);
	
	cout << "After Inversion Str is = " << Str << endl;
}

