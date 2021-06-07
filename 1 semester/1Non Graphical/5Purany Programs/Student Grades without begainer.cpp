// Student Grades without begainer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std ;

int main()
{
	cout << "                        STUDENT GRADES" << endl << endl ;
	int marks ;

	cout << "Enter the students marks here(Out of 100)." ;
	cin >> marks ;

	cout << endl ;

	if (marks >= 85)
	{
		cout << "Cogradulations! Your grade is A+." ;
	}

	else if (marks >= 80)
	{
		cout << "Your grade is A." ;
	}

	else if (marks >= 75)
	{
		cout << "Your grade is B+." ;
	}

	else if (marks >= 70)
	{
		cout << "Your grade is B." ;
	}

	else if (marks >= 65)
	{
		cout << "Your grade is B-" ;
	}

	else if (marks >= 50)
	{
		cout << "Your grade is C." ;
	}

	else
	{
		cout << "Ahhh! You are fail." ;
	}

	cout << endl << endl << endl ;
	return 0;
}

