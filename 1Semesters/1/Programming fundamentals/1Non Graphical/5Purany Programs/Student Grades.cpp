// Student Grades.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{

	int reloader = 2 ;

	do{
		if (reloader == 2)
		{
			cout << "                        STUDENT GRADES" << endl << endl ;
		}

		int marks ;

		cout << "Enter the students marks here(Out of 100)." ;
		cin >> marks ;

		
			for (; marks > 100 | marks < 0; )
			{
				cout << endl ;
				cout << "Its impossible. Please enter again." ;
				cin >> marks ;
			}

		
			cout << endl ;
		
			if (marks >= 85)
			{
				cout << "Cogradulations! Your grade is A+.";
			}

			else if (marks >= 80)
			{
				cout << "Your grade is A.";
			}

			else if (marks >= 75)
			{
				cout << "Your grade is B+.";
			}

			else if (marks >= 70)
			{
				cout << "Your grade is B.";
			}

			else if (marks >= 65)
			{
				cout << "Your grade is B-";
			}

			else if (marks >= 50)
			{
				cout << "Your grade is C.";
			}

			else
			{
				cout << "Ahhh! You are fail.";
			}

			cout << endl << endl << endl ;

		

		cout << "To enter the marks again please enter '1'." << endl ;
		cout << "To reload program enter '2'."               << endl ;
		cout << "To close program enter any key."            << endl << endl ;

		cout << "           Enter here       =   " ;
		cin >> reloader ;

		if (reloader == 2)
		{
			 system("CLS") ;
		}
		else
		{
			cout << endl << endl ;
		}

		

	} while (reloader == 1 | reloader == 2) ;

	return 0;
}

