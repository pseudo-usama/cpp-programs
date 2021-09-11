#include "iostream"
#include "sys/ipc.h"
#include "sys/shm.h"
#include "stdio.h"
using namespace std;

int main() {
	// ftok to generate unique key
	key_t key = ftok("shmfile", 65);
	cout << "Generated Key is  : " << key << endl;

	// key.t shm ID
	int shmid = shmget(key, 1024, 0666|IPC_CREAT);

/*	PROTOTYPE: int shmget ( key_t key, int size, int shmflg );
	RETURNS: shared memory segment identifier on success
			-1 on error: errno = EINVAL (Invalid segment size specified)
                                  EEXIST (Segment exists, cannot create)
                                  EIDRM (Segment is marked for deletion, or was removed)
                                  ENOENT (Segment does not exist)
                                  EACCES (Permission denied)
                                  ENOMEM (Not enough memory to create segment)

	More Details: https://www.tldp.org/LDP/lpg/node69.html
*/

	// attach to shm
	char *str = (char*) shmat(shmid, (void*)0, 0);
/*
	PROTOTYPE: int shmat ( int shmid, char *shmaddr, int shmflg);
	RETURNS: address at which segment was attached to the process, or
			-1 on error: errno = EINVAL (Invalid IPC ID value or attach address passed)
                                  ENOMEM (Not enough memory to attach segment)
                                  EACCES (Permission denied)

	More Details: http://tldp.org/LDP/lpg/node70.html
*/

	cout << "Enter Data: ";
	cin >> str;
	cout << "Data written in shm is " << str << endl;

	//detach from shm
	shmdt(str);
	return(0);
}
