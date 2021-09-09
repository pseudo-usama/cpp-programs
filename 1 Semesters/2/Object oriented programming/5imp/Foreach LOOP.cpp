// Foreach LOOP.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include"iostream"
#include"string"
#include"string.h"
#include"conio.h"
#include <vector>
#include "fstream"
#include "windows.h"

using namespace std;
void Fn();

void main()	{
	vector<string> cities;
	cities.push_back("hahaha");
	cities.push_back("hihi hi");

	// Use C++ "for each" construct syntax
	// to iterate over "cities" vector
	for (string& city : cities)
	{
		cout << city << endl;
	}

}

