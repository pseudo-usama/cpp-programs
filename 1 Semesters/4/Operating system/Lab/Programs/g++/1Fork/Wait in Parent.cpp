#include "iostream"
#include "stdio.h"
#include "unistd.h"
#include "sys/wait.h"		// For wait()
using namespace std;

int main() {
	int pid = fork();

	if (pid == 0) {
		cout << "This is Child.\n";
		cout << "This is Child.\n";
		cout << "This is Child.\n";
		cout << "This is Child.\n";
		cout << "This is Child.\n";

	}
	else if (pid > 0) {
		cout << "This is Parent. Child Process Id is:  " << pid << endl;
		cout << "This is Parent. Child Process Id is:  " << pid << endl;
		wait(NULL);	// If we add wait() then Parent will wait for Child to Terminate
		cout << "This is Parent. Child Process Id is:  " << pid << endl;
		cout << "This is Parent. Child Process Id is:  " << pid << endl;

	}

	return 0;
}
