#include "iostream"
#include "stdio.h"
#include "unistd.h"
using namespace std;

int main() {
	fork();
	fork();

	cout << "Hello World\n";
	
	fork();		// This fork call have no effect

	return (0);
}
