// Password star.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"string"
#include"iostream"
#include"conio.h"
using namespace std;

string GetPassword(){
	char Password[20];
	char Get;

	for (int i = 0;;){
		Get = _getch();

		if ((Get >= 'a'&&Get <= 'z') || (Get >= 'A'&&Get <= 'Z') || (Get >= '0'&&Get <= '9')) {
			Password[i] = Get;
			cout << "*";
			i++;
		}
		else if (Get == '\b') {
			cout << "\b \b";
			i--;
		}
		else if (Get == '\r'){
			Password[i] = '\0';
			break;
		}
	}
	return(string(Password));
}

int _tmain(int argc, _TCHAR* argv[])
{
	string Password = GetPassword();

	cout << Password;

	return 0;
}

