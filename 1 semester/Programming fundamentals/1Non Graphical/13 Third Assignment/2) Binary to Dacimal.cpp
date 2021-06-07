// 2) Binary to Dacimal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int BinaryToDacimal(long binary) {

	int dacimal, answer = 0;

	for (int power = 0; power < 10; power++)
	{
		dacimal = binary % 10;
		binary = binary / 10;
		answer = answer + dacimal * pow(2, power);
	}
	return answer;
}

int main()
{
	int binary, answer;

	cout << "Enter a binary number.(maximum 9 digits)        =   ";
	cin >> binary;

	answer = BinaryToDacimal(binary);

	cout << "That number in dacimal is                       =   " << answer;

	return 0;
}

