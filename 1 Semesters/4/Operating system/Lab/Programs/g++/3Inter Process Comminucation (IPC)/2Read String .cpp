#include "iostream"
#include "sys/shm.h"
#include "sys/ipc.h"
#include "stdio.h"
using namespace std;

int main() {
	// ftol to generate unique key
	key_t key = ftok("shmfile", 65);
	cout << "The generated key is :  " << key << endl;

	// key shm ID
	int shmid = shmget(key, 1024, 0666|IPC_CREAT);

	// attach to shm
	char *str = (char*) shmat(shmid, (void*)0, 0);

	cout << "Data read from shm is " << str << endl;

	// detach
	shmdt(str);
	shmctl(shmid, IPC_RMID, NULL);		// This is destroying the shared memory

	return(0);
}
