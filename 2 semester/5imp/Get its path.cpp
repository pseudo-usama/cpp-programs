// Get its path.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"iostream"
#include"string"
#include"string.h"
#include "direct.h"
#include"conio.h"
#include "fstream"
#include "windows.h"

using namespace std;


void main()	{

	//This not works
	/*
	cout << "__FILE__ => " << __FILE__ << endl;
	char absolutePath[_MAX_PATH];
	_fullpath(absolutePath, "Test.cpp", _MAX_PATH);
	cout << absolutePath << "n";
	*/

	char* cwd = _getcwd(0, 0); // **** microsoft specific ****
	std::string working_directory(cwd);
	std::free(cwd);
	cout << working_directory;

	cout << endl;
	cin.ignore();
}


//another method
/*


int main(int argc, char *argv[])
{
for (int i = 0; argv[i] != '\0'; i++) {
cout << *(argv+i);
}
return 0;
}



*/