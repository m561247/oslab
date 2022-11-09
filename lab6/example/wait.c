#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	pid_t new_pid;

	new_pid = fork();

	switch(new_pid)
	{
		case -1 :
			printf("fork error\n");
			break;
		case 0 : 
			printf("\n-------------------this is chiild process-------------------\n");
			printf("pid : %d\n parent pid : %d\n", getpid(), getppid());
			printf("--------------------------------------------------------------\n");
			break;
		default :
			wait(NULL);
			printf("\n-------------------this is parent  process-------------------\n");
			printf("pid : %d\n child pid : %d\n", getpid(), new_pid);
			printf("---------------------------------------------------------------\n");
			break;
	}
	return 0;
}
