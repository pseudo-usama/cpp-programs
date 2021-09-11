// Mujhy is Program ki smj ni ha

#include<signal.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
#include<iostream>
using namespace std;

int sigCount = 0;

void sigHandler(int sigNum) {
	cout << "Signal received is " << sigNum << endl;
	sigCount++;
	cout << "Total Signals are " << sigCount << endl;
}

int main() {
	signal(SIGINT, SIG_DFL);

	while(1) {
		cout << "Hello! My Id is :  " << getpid() << endl;
		sleep(1);
	}

	return 0;
}
