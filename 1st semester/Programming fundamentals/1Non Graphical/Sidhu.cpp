#include "stdafx.h"
#include "iostream"
#include "conio.h"
using namespace std;

int main()
{
	
	char ch;

	for (int i = -1000; i <= 1000; i++)
	{
		ch = i;
		cout << "ASCII value of " << ch << " = " << i << endl;
	}
    return 0;
}