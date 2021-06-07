// pahary with while.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std ;

int main()
{
	cout << "                     PAHARY" << endl << endl << endl ;

	int start, end, TableName, reloader;
	do{

		cout << "Enter the table name.            =       ";
		cin >> TableName;

		cout << "Enter starting point.            =       ";
		cin >> start;
		
		cout << "Enter the ending point.          =       ";
		cin >> end;

		cout << endl;

		while (start > end)
		{
			cout << "ERROR. Your table should be in ascending order." << endl;
			cout << "Enter starting point.          =       ";
			cin >> start;

			cout << "Enter the ending point.        =       ";
			cin >> end;

			cout << endl;
		}
		while (start <= end)
		{
			cout << TableName << " * " << start << " = " << TableName * start << endl;

			start++;
		}

		cout << endl << endl ;

		cout << "Enter '1' to enter values again." << endl ;
		cout << "Enter '2' to realod program."     << endl ;
		cout << "Enter any key to close program."  << endl ;
		cout << "            Enter here   " ;
		cin >> reloader;

		if (reloader == 2)
		{
			system("CLS");
		}
	} while (reloader == 1 | reloader == 2) ;
	
	cout << endl << endl << endl ;

	return 0;
}

