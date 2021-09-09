		// Hide already exist file.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



#include "stdafx.h"
#include "iostream"
#include "windows.h"
#include <fstream>
using namespace std;



void main() {
	//Hide already exist files

	DWORD attributes = GetFileAttributes(L"E:\\MyFile.txt");
	SetFileAttributes(L"E:\\MyFile.txt", attributes + FILE_ATTRIBUTE_HIDDEN);
	cout << attributes;
}



