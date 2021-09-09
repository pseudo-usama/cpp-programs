// calculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std ;

int main()
{

	int reloader = 2 ;

	do{

		if (reloader == 2)
		{
			cout << "                        CALCULATOR" << endl << endl ;
		}

		int FirstNumber, SecondNumber, OprationSelector, Reminder;
		float a;

		cout << "Please enter the first digit      =              ";
		cin >> FirstNumber;

		while (-30000 > FirstNumber | FirstNumber > 30000)
		{
			cout << endl << "Out of memory. Please select a number from '30000' to'-30000'." << endl << endl;
			cout << "Please enter the first digit      =              ";
			cin >> FirstNumber;
		}

		cout << "Please enter the second digit     =              ";
		cin >> SecondNumber;

		while (-30000 > SecondNumber | SecondNumber > 30000)
		{
			cout << endl << "Out of memory. Please select a number from '30000' to'-30000'." << endl << endl;
			cout << "Please enter the first digit      =              ";
			cin >> SecondNumber;
		}

		Reminder = FirstNumber % SecondNumber; // ya nichay division k lya lya hy
		a = FirstNumber / SecondNumber;        // ya b division k lya hy


		cout << endl;

		cout << "Now please select the opration to be used." << endl << endl;
		cout << "For ADDITION please enter               1" << endl;
		cout << "For SUBTRACTION please enter            2" << endl;
		cout << "For MULTIPLICATION please enter         3" << endl;
		cout << "For DIVISION please enter               4" << endl;
		cout << "           Enter here          ";

		cin >> OprationSelector;

		while (1 > OprationSelector | OprationSelector > 4)
		{
			cout << "You number is invalid. Please select from 1 to 4." << endl;
			cout << "           Enter here          ";
			cin >> OprationSelector;
		}
		cout << endl << endl;
		cout << "    The solution is            ";
		if (OprationSelector == 1)
		{
			cout << FirstNumber << "+" << SecondNumber << "=" << FirstNumber + SecondNumber;
		}
		else if (OprationSelector == 2)
		{
			cout << FirstNumber << "-" << SecondNumber << "=" << FirstNumber - SecondNumber;
		}
		else if (OprationSelector == 3)
		{
			cout << FirstNumber << "*" << SecondNumber << "=" << FirstNumber * SecondNumber;
		}
		else if (OprationSelector == 4)
		{
			if (Reminder == 0)
			{
				cout << FirstNumber << "/" << SecondNumber << "=" << FirstNumber / SecondNumber;
			}
			else
			{
				cout << FirstNumber << " / " << SecondNumber << " = " << a;
				cout << " or (" << SecondNumber << "*" << FirstNumber / SecondNumber << "+" << Reminder << ") / " << SecondNumber;
			}
		}

		cout << endl << endl ;

		cout << "To enter values again enter '1'." << endl ;
		cout << "To reload program enter '2'."     << endl ;
		cout << "To close program enter any key."  << endl ;
		cout << "           Enter here          " ;
		cin >> reloader ;

		if (reloader == 2)
		{
			system("CLS") ;
		}

		if (reloader == 1)
		{
			cout << endl << endl;
		}

	}while(reloader == 1 | reloader == 2) ;
	return 0;
}

