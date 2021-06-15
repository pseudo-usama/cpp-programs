// 2 Assingment (Ibrahim).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string"
#include "iostream"
using namespace std;

class student
{
private:
	string name;
	string email;
	string id;
public:
	student()
	{													//Constructur with no arrguments
		name = "Ali";
		email = "ali@gmail.com";
		id = "17114119-006";
	}
	student(string a, string b, string c)				//Costructur with three arrguments
	{		
		name = a;
		email = b;
		id = c;
	}
	student(const student &z)							//Copy Constructer
	{
		name = z.name;
		email = z.email;
		id = z.id;
	}
	void Show()
	{
		cout << name << endl;
		cout << email << endl;
		cout << id << endl;
	}
	~student()
	{
		cout << "Destructur Called" << endl;
	}
};

void main()
{
	student a, b("Zaheer", "zaheer@gmail.com", "17114119-001"), c=a;															//Object with no parameter
	a.Show();

	cout << endl;

	b.Show();

	cout << endl;

	c.Show();

	cout << endl;
}

