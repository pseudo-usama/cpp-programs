// Oprator Overloading.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

class A{
private:
	int a;

public:
	A() { a = 0; }

	void Show() {
		cout << a << endl;
	}

	void operator --(){
		a++;
	}
};

int main()
{
	A ob;

	ob.Show();

	ob--;

	ob.Show();

	return 0;
}

