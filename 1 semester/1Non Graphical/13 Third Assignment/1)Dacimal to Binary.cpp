// 1)Dacimal to Binary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int   answer = 0, ReverseBinary = 2, two = 20, one = 0, holder = 0;
	long dacimal, binary;

	cout << "Enter a dacimal number.(maximum 5 digits)                =    ";
	cin >> dacimal;

	for (; dacimal < 0 || dacimal > 500;)
	{
		cout << "Enter a positive number and should be 500(maximum)       =    ";
		cin >> dacimal;
	}

	cout << endl << endl;

	cout << "That number in binary is         =    ";

	if (dacimal == 1)
	{
		cout << "1";
	}
	else if (dacimal == 0)
	{
		cout << "0";
	}
	else
	{

	for (int a = 1; dacimal != 1; a++)
		{
			ReverseBinary = dacimal % 2;
			dacimal = dacimal / 2;

			if (ReverseBinary == 1)
			{
				holder = 1;
				holder = one + holder + two;
				holder = holder * 10;
			}
			else if (ReverseBinary == 0)
			{
				holder = two + holder * 10;
			}
				two = 0;
				one = 1;
			}
				holder = holder * 10 + 1;

		for (; holder != 2;)
			{
				binary = holder % 10;
				holder = holder / 10;

				if (binary == 1)
				{
					answer = answer * 10 + 1;
				}
				else if (binary == 0)
				{
					answer = answer * 10;
				}
			}
			cout << answer;

		}
		return 0;
}

