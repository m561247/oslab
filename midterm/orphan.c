#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid;

	pid = fork();

	if (pid < 0) {
		fprintf(stderr,"Unable to create child process\n");
		return -1;
	}
	else if (pid == 0) {
		sleep(100);
	}
	else {
		return 0;
	}
}



