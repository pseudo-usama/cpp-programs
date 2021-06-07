// White Wash cost.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

struct Area{

	int length;
	int width;
};

struct Volume{

	Area area;
	int height;
};

int main()
{
	Volume room;

	cout << "Enter the LENGTH of room   = ";
	cin >> room.area.length;

	cout << "Enter the WIDTH of room    = ";
	cin >> room.area.width;

	cout << "Enter the HEIGHT of room   = ";
	cin >> room.height;
	
	cout << "Area of ROOM    = " << 2 * room.height * (room.area.width + room.area.length) + room.area.width * room.area.length;

	return 0;
}