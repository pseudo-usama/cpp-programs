// Three Classes in Circle Inheritance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

class C;

class A: public C{
private:
	int a;

public:
	void input(){
		inputC();

		cout << "Enter a  = ";
		cin >> a;
	}
	void show(){
		cout << "a is     = " << a << endl;
	}
};

class B: public A{
private:
	int b;

public:
	void inputB(){
		input();

		cout << "Enter b  = ";
		cin >> b;
	}
	void showB(){
		show();

		cout << "b is     = " << b << endl;
	}
};

class C: public B{
private:
	int c;

public:
	void inputC(){
		inputB();

		cout << "Enter c  = ";
		cin >> c;
	}
	void showC(){
		showB();

		cout << "c is     = " << c << endl;
	}
};

C z;

int main()
{
	

	z.inputC();
	z.showC();

	return 0;
}

