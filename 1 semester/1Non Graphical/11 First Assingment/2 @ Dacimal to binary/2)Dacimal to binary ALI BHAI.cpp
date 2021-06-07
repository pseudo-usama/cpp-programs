// 2)Dacimal to binary ALI BHAI.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int input, ReverseBinary = 2, ActualBinary = 0, remainder;
	
	do{
		cout << "Enter a positive integer       =    ";
		cin >> input;
	  }while (input < 0);
	
	if (input < 2)
	{
		ActualBinary = input; 
	}
	else
	{
		for (; input > 1;)
		{
			remainder = input % 2;
			input = input / 2;

			if (remainder == 0)
			{
				ReverseBinary = ReverseBinary * 10; 
			}
			else
			{
				ReverseBinary = ReverseBinary * 10 + 1; 
			}
		}

		ReverseBinary = ReverseBinary * 10 + 1;
		
		for (; ReverseBinary != 2;)
		{

			remainder = ReverseBinary % 10;
			ReverseBinary = ReverseBinary / 10;

			if (remainder == 0)
			{
				ActualBinary = ActualBinary * 10;
			}
			else
			{
				ActualBinary = ActualBinary * 10 + 1; 
			}
		}
	}

	cout << "Binary Value                   =    " << ActualBinary << endl;

	return 0;
}

