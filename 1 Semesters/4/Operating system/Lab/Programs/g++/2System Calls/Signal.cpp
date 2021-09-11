// Mujhy is program ki bilkul smj ni ha

#include<stdio.h>
#include<wait.h>
#include<signal.h>
#include<unistd.h>
#include<sys/types.h>
#include<iostream>
using namespace std;

int val = 10;

void handler(int sig) {
	val += 5;
}

int main() {
	pid_t pid;
	signal(SIGCHLD, handler);

	if ((pid = fork()) == 0) {
	        val -= 3;
        	exit(0);
	}

	waitpid(pid, NULL, 0);
	printf("val = %d\n", val);

	exit(0);
}
