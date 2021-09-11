// Ya Program mujhy sahi tarha ni ata

// C program to illustrate use of fork() &
// exec() system call

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <string.h>

int main() {
	int ret = 1;
	int status;
	pid_t pid = fork();

	if (pid == -1) {	// Fork Failed
		printf("Can't fork, error occured\n");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0) {	// Child Process
		printf("Child process, pid = %u\n", getpid());

		// the argv list first argument should point to
		// filename associated with file being executed
		// the array pointer must be terminated by NULL
		// pointer
		// char *a = "ls";
		char* x[] = {(char*) malloc(strlen("ls")+1)}; // +1 for the terminator
		strcpy(x[0],"ls");
		// the execv() only return if error occured.
		// The return value is -1
		execv("ls",x);
		exit(0);
	}
	else {	// Parent Process
		printf("Parent process, pid = %u\n", getppid());

		// the parent process calls waitpid() on the child
		// waitpid() system call suspends execution of
		// calling process until a child specified by pid
		// argument has changed state
		// see wait() man page for all the flags or options
		// used here
		if (waitpid(pid, &status, 0) > 0) {
			if (WIFEXITED(status) && !WEXITSTATUS(status))
				printf("program execution successfull\n");
			else if (WIFEXITED(status) && WEXITSTATUS(status)) {
				if (WEXITSTATUS(status) == 127)	// execv failed
					printf("execv failed\n");
				else
					printf("program terminated normally, but returned a non-zero status\n");
			}
			else
				printf("program didn't terminate normally\n");
		}
		else {	// waitpid() failed
			printf("waitpid() failed\n");
		}

		exit(0);
	}

	return 0;
}
