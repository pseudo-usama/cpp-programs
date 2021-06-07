// Akram Aslam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std ;

int main()
{
	int reloader ;
	do{

		int First, Second ;

		cout << "Enter the first value.        =   " ;
		cin >> First ;
		
		cout << "Enter the second value.       =   " ;
		cin >> Second ;

		while (Second == First)
		{
			cout << endl ;
			cout << "ERROR. You enter this" << endl ;
			cout << "value already. Please" << endl ;
			cout << "enter other number."   << endl << endl ;
			cout << "Enter the second value.       =   " ;
			cin >> Second ;
		}

		cout << endl << endl << endl ;

		cout << "To enter the values again enter '1'." << endl ;
		cout << "To reload the program enter '2'."     << endl ;
		cout << "To close program enter any key."      << endl ;

		cout << "         Enter here    =        " ;
		cin >> reloader ;

		if (reloader == 2)
		{
		   cout << system("CLS") ;
		}

	} while (reloader == 1 || reloader == 2) ;

	return 0;
}

