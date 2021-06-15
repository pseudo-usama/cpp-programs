// 21ATM transection.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{

	int password = 123, password2 = 123, balance = 500000, withdraw, OptionSelector;

	cout << "Enter your ATM card." << endl;
	cout << "Enter the password.                        =   ";
	cin >> password;

	for (; password != 123;)
	{
		cout << "Incorrect password.";
		cin >> password;
	}
	for (; ; )
	{
	cout << "To check balance enter      1" << endl;
	cout << "For withdraw enter          2" << endl;
	cout << "To change password          3" << endl;
	cout << "For mini statement          4" << endl;
	cin >> OptionSelector;
	if (OptionSelector == 1)
	{
		cout << "The balance is " << balance << endl;
		cout << endl << endl;
	}
	else if (OptionSelector == 2)
	{
		cout << "Enter an amount to withdraw.               =   ";
		cin >> withdraw;

		for (; withdraw > balance;)
		{
			cout << "Enter an amount less than your balance.    =   ";
			cin >> withdraw;
		}

		balance = balance - withdraw;

		cout << "Your remaining balance is                  =   " << balance << endl;
		cout << endl << endl;
	}
	else if (OptionSelector == 3)
	{
		cout << "Enter a new password.       =   ";
		cin >> password;
		cout << "Conferm password            =   ";
		cin >> password2;
		for (; password2 != password;)
		{
			cout << "Not match" << endl;
			cout << "Enter a new password.       =   ";
			cin >> password;
			cout << "Conferm password            =   ";
			cin >> password2;
		}
		cout << endl << endl;
	}
	else if (OptionSelector == 4)
	{
		cout << "Account no       125426546-075" << endl;
		cout << "Card no          3475876786-766" << endl;
		cout << "ATM CW           3000" << endl;
		cout << "CM TRANSFER CR   41545" << endl;
		cout << endl << endl;
	}
}
	return 0;
}

