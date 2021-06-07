// function my name.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

void usama(int &reciver)
{
	reciver = reciver + 10;

}
int main()
{
	int a;
	cin >> a;
	usama(a);

	cout << a;

	return 0;
}

