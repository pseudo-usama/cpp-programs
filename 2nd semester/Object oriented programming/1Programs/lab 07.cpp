// lab 07.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string"
using namespace std;

class Employee{
private:
	string Name;
	string Id;

public:
	void PutEmployee(){
		cout << "Enter your Name     = ";
		cin >> Name;

		cout << "Enter your Id       = ";
		cin >> Id;
	}
	void GetEmployee(){
		cout << "Name                = " << Name << endl;
		cout << "Id                  = " << Id << endl;
	}
};

class Student{
private:
	string Program;
	string DateComlition;

public:
	void PutStudent(){
		cout << "Enter your Program              = ";
		cin >> Program;

		cout << "Enter your Date of Complition   = ";
		cin >> DateComlition;
	}
	void GetStudent(){
		cout << "Program                         = " << Program << endl;
		cout << "Dte of Complition               = " << DateComlition << endl;
	}
};

class Manager :public Employee, public Student{
private:
	string Designation;
	string Salary;

public:
	void PutManager(){
		PutEmployee();
		PutStudent();

		cout << "Enter your Designastion         = ";
		cin >> Designation;

		cout << "Enter your Salary               = ";
		cin >> Salary;
	}
	void GetManager(){
		GetEmployee();
		GetStudent();

		cout << "Your Designation is             = " << Designation << endl;
		cout << "Your Salary is                  = " << Salary << endl;
	}
};

class Scientist :public Employee, public Student{
private:
	string ResearchArea;
	string NamePublition;
	string DatePublition;

public:
	void PutScientist(){
		PutEmployee();
		PutStudent();

		cout << "Enter Research Area              = ";
		cin >> ResearchArea;

		cout << "Enter Name of Publication        = ";
		cin >> NamePublition;

		cout << "Enter Date of Publication        = ";
		cin >> DatePublition;
	}
	void GetScientist(){
		GetEmployee();
		GetStudent();

		cout << "Reach Area                       = " << ResearchArea << endl;
		cout << "Name Publication                 = " << NamePublition << endl;
		cout << "Date of Publication              = " << DatePublition << endl;
	}
};

int main()
{
	Manager a;

	cout << "Enter Entries against Manager" << endl << endl;

	a.PutManager();
	a.GetManager();

	Scientist z;

	cout << endl << "Enter Entries against Scientist" << endl << endl;

	z.PutScientist();
	z.GetScientist();

	return 0;
}

