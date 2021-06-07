// 6Binary to dacimal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
		
	int binary, dacimal, answer = 0;

	cout << "Enter a binary number.(maximum 9 digits)        =   ";
	cin >> binary;

	cout << "That number in dacimal is                       =   ";

	for (int power = 0;power < 10; power++)
	{
		dacimal = binary % 10;
		binary = binary / 10;
		answer = answer + dacimal * pow(2, power);
	}
	cout << answer;

	return 0;
}

