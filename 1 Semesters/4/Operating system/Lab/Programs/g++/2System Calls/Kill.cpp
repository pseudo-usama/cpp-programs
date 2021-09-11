#include<iostream>
#include<signal.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
using namespace std;

int main() {
	int i = 0;

	while(1) {
		cout << "This is " << i << " iteration. My Id is :  " << getpid() << endl;

		if(i == 5)
			kill(getpid(), SIGTERM);

		i++;
		sleep(1);
	}

	return 0;
}
