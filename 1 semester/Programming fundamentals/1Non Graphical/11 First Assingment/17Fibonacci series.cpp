// 17Fibonacci series.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{

	int a = 0, b = 1, range = 0, answer = 0, AnswerPrevious, dicider = 0;

	cout << "Enter the maximum point.          =    ";
	cin >> range;
	for (; range < 0 || range > 99999;)
	{
		cout << "The a number from 1 to 99999.       =    ";
		cin >> range;
	}
	cout << "The series is " << endl << a << endl ; 

	for (; answer < range;)
	{
		if (dicider == 0)
		cout << b << endl;

		if (dicider == 1)
		{
			AnswerPrevious = answer;
		}
		answer = answer + b;
		if (answer <= range)
		{
			cout << answer << endl;
		}
		if (dicider == 1)
		{
			b = AnswerPrevious;
		}
		dicider = 1;
	}

	return 0;
}

