#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
	pid_t new_pid;
	
	new_pid = fork();

	switch(new_pid)
	{
		case -1:
			printf("fork error\n");
		case  0:
			printf("----------------this is child process------------\n");
			printf("Pid:%d\nparent pid : %d\n", getpid(), getppid());
			printf("---------------------------------------------------\n");
			break;
		default:
			wait(NULL); // wait until child process finished
			printf("----------------this is parent process------------\n");
			printf("Pid:%d\nchild pid : %d\n", getpid(), new_pid);
			printf("---------------------------------------------------\n");
			break;
	}
	return 0;

}

