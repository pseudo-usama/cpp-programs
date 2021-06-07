// 1Tol Plaze pasing very  easy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;


int main()
{
	char army, licence, idCard, nationality, decider, LicenceDecider;
	do{
		cout << "Do you belong to army?(Y/N)";
		cin >> army;

		switch (army)
		{
		case 'y':
		case 'Y':
		{
					decider = 1;
					break;
		}
		case 'n':
		case 'N':
		{
					decider = 0;
					break;
		}
		default:
		{
				   cout << "You enter an invalid key.";
				   decider = 2;
				   cout << endl;
				   break;
		}
		}
	}while(decider == 2);

	do{
	switch (decider)
	{
	case 1:
	{
			  cout << "Do you have licnece?(Y/N)";
			  cin >> licence;
			  LicenceDecider = 1;
	}
	}

	
		switch (LicenceDecider == 1 && licence)
		{
		case 'y':
		case 'Y':
		{
					cout << "Welcom...!!!You can pass throught the tool plaza.";
					decider = 1;
					break;
		}

		case 'n':
		case 'N':
		{
					decider = 0;
					break;
		}
		default:
		{
				   cout << "You enter an invalid key";
				   decider = 2;
				   break;
		}
		}
	} while (decider == 2);



	return 0;
}

