#include <stdio.h>
#include <unistd.h>

int main() {
	fork();
	fork() && fork() || fork();
	fork();

	printf("forked\n");
	return 0;
}

// https://www.geeksforgeeks.org/fork-system-call/
