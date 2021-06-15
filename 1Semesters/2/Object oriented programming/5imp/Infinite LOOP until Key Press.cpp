// Infinite LOOP until Key Press.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "conio.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	// if (GetAsyncKeyState(VK_ESCAPE))

	while (1)
	{
		if (_kbhit()) {
			break;
		}
		cout << "asd" << endl;
	}

	return 0;
}



// ak or tarika

/*

#include <signal.h>

void sigint_handler(int sig_num)
{
// Reset handler to catch SIGINT next time.
//Refer http://en.cppreference.com/w/c/program/signal 
printf("\n User provided signal handler for Ctrl+C \n");

// Do a graceful cleanup of the program like: free memory/resources/etc and exit 
exit(0);
}
void main() {
	signal(SIGINT, sigint_handler);

	while (1)
	{
		printf("Inside program logic loop\n");
	}
}




*/