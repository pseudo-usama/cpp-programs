// Begainer.cpp : Defines the entry point for the console application.
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
			cout << "                        STUDENT GRADES" << endl << endl;
		}



		//enter the whole program here

		cout << endl << endl << endl << endl << endl << endl;







		cout << "To enter the marks again please enter  '1'." << endl;
		cout << "To reload program enter                '2'." << endl;
		cout << "To close program enter                 '0'." << endl << endl;

		cout << "           Enter here       =   ";
		cin >> reloader;

		if (reloader == 2)
		{
			system("CLS");
		}
		else
		{
			cout << endl << endl;
		}



	} while (reloader != 0);

	return 0;
}