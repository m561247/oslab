#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int v1 = 10;
int main() {
	int v2 = 20;
	char str[10];
	pid_t pid;
	pid = fork();
	if (pid == 0) {
		v1 = 30;
		v2 = 40;
	}
	pid = fork(); 
	if (pid == 0) {
		sprintf(str, "%d", v1 + v2);
		// execute p2.c
		execlp("./p2", "p2.c", str,NULL);
	}
	else if (pid > 0) {
		wait(NULL);
		printf("P1: %d %d\n", v1, v2);
	}
	return 0;
}



