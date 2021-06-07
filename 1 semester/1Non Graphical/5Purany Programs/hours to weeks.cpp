// hours to weeks.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int reloader = 2;

	do{
		if (reloader == 2)
		{
			cout << "                  Hours to Weeks, Days Converter" << endl << endl ;
		}

		long hours, weeks, days ;
		

		cout << "Please enter time in hours       =     ";
		cin >> hours;

		cout << endl;

		days = hours / 24;
		hours = hours % 24;

		weeks = days / 7;
		days = days % 7;

		cout << "The time is " << endl;

		cout << "                        Weeks    =     " << weeks << endl;
		cout << "                        Days     =     " << days << endl;
		cout << "                        Hours    =     " << hours << endl;

		cout << endl << endl ;

		cout << "To enter the values again enter '1'." << endl ;
		cout << "To reload program enter '2'."         << endl ;
		cout << "To close program enter any key."      << endl ;
		cout << "            Enter here   =    " ;

			cin >> reloader ;

		if (reloader == 2)
		{
			system("CLS") ;
		}

		if (reloader == 1 | reloader > 2 | reloader <= 0)
		{
			cout << endl << endl;
		}

	} while (reloader == 1 | reloader == 2) ;
	return 0;
}

