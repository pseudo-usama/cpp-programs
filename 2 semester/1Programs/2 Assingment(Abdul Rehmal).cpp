// 2 Assingment(Abdul Rehmal).cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "string"
#include "iostream"
using namespace std;

class student
{
private:
	string N;
	string E;
	string I;
public:
	student()
	{
		N = "Hassan";
		E = "hassan@gmail.com";
		I = "17114119-100";
	}

	student(string x, string y, string z)
	{
		N = x;
		E = y;
		I = z;
	}

	student(const student &S)
	{
		N = S.N;
		E = S.E;
		I = S.I;
	}

	~student()
	{
		cout << "Destructur Call" << endl;
	}

	void Show()
	{
		cout << N << endl;
		cout << E << endl;
		cout << I << endl;
	}
};

void main()
{
	student X, Y("Abdul Rehman", "AbdulRehman@gmail.com", "17114119-022"), Z = X;
	X.Show();

	cout << endl;

	Y.Show();

	cout << endl;

	Z.Show();

	cout << endl;
}

