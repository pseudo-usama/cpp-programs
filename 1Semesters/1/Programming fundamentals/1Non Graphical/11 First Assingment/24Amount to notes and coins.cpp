// 24Amount to notes and coins.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	long amount;
	int hazar, panchso, soo, panchas, biss, dass, panch, doo, ak;

	cout << "Enter the amount(maximum 9 digits).  =      ";
	cin >> amount;
	for (; amount < 0 || amount >> 999999999;)
	{
		cout << "Enter the amount(maximum 9 digits).    " << endl;
		cout << "And greater than zero                =";
		cin >> amount;
	}

	hazar = amount / 1000;
	amount = amount % 1000;

	panchso = amount / 500;
	amount = amount % 500;

	soo = amount / 100;
	amount = amount % 100;

	panchas = amount / 50;
	amount = amount % 50;

	biss = amount / 20;
	amount = amount % 20;

	dass = amount / 10;
	amount = amount % 10;

	panch = amount / 5;
	amount = amount % 5;

	doo = amount / 2;
	amount = amount % 2;

	ak = amount;

	cout << endl;

	cout << "There are " << endl;
	cout << "Note(s) of thousand             "  << hazar   << endl;
	cout << "Note(s) of five hundard         "  << panchso << endl;
	cout << "Note(s) of hundard              "  << soo     << endl;
	cout << "Note(s) of fifty                "  << panchas << endl;
	cout << "Note(s) of twenty               "  << biss    << endl;
	cout << "Note(s) of ten                  "  << dass    << endl;
	cout << "Coin(s) of five                 "  << panch   << endl;
	cout << "Coin(s) of two                  "  << doo     << endl;
	cout << "Coin(s) of one                  "  << ak;

	return 0;
}

