#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
	pid_t pid;
	pid = fork(); 
	if (pid == 0)
		printf("C2: %s\n",argv[1]);
	else if (pid > 0) {
		wait(NULL);
		printf("P2: %s\n",argv[1]);
	}
	return 0;
}








