// switch 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	char input;

	cout << "Enter a word.";
	cin >> input;

	switch (input)
	{
	case 'a':
	{
				cout << "aaaaa";
				break;
	}
	case 'b':
	{
				cout << "biiiii";
				break;
	}
	case 'c':
	{
				cout << "ciiiiiii";
				break;
	}
	default:
		break;
	}

	return 0;
}

