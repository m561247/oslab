#include<stdio.h>
#include<unistd.h>

int main()
{
	pid_t new_pid;

	new_pid = fork();

	if (new_pid < 0) {
		printf("fork error\n");
		return 0;
	} else if (new_pid == 0) {
		printf("\n-----------------this is child process--------------\n");
		printf("Pid:%d\nParent pid:%d\n", getpid(), getppid());
		printf("------------------------------------------------------\n");
		return 0;
	} else {
		printf("\n-----------------this is parent process--------------\n");
		printf("Pid:%d\nChild pid:%d\n", getpid(), new_pid);
		printf("------------------------------------------------------\n");
		return 0;
	}
}
