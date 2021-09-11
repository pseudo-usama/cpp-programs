#include "iostream"
#include "unistd.h"
#include "stdio.h"
using namespace std;

int main() {
	int pid = fork();

	switch(pid) {
		case 0:
			cout << "This is Child\n";
			cout << "My Id is:        " << getpid() << endl;
			cout << "My Parent Id is: " << getppid() << endl << endl;
		break;
		case -1:
			cout << "Sorry! Fork call Failed.\n";
		break;
		default:
			cout << "This is Parent.\n";
			cout << "My Id is:        " << getpid() << endl;
			cout << "My Parent Id is: " << getppid() << endl;
			cout << "My Child Id is:  " << pid << endl << endl;
		break;
	}

	return 0;
}
