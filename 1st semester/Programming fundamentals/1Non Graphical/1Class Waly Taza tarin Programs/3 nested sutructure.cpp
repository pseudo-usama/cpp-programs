// 3 nested sutructure.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	struct ANIMAL {
		int age;
	};

	struct PERSON {
		ANIMAL animal;
		char name[10];
		char FatherName[10];
		char number[15];
	};

	struct STUDENT {
		PERSON person;
		char RollNo[15];
		int fees;
	};

	STUDENT student;

	cin >> student.fees;

	cin >> student.RollNo;

	cin >> student.person.number;

	cin >> student.person.name;

	cin >> student.person.FatherName;

	cin >> student.person.animal.age;

	return 0;
}

