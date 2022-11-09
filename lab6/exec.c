#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>
int main()
{
	execlp("/bin/ls", "ls", "-l", NULL);
	
	pid_t new_pid;
	new_pid = fork();

	switch(new_pid)
	{
		case -1:
			printf("fork error\n");
			break;
		case  0: 
			execlp("/bin/ls", "ls", "-l", NULL);
			exit(0);
			break;
		default:
			printf("\n----------------this is parent process------------\n");
			printf("Pid:%d\nchild pid : %d\n", getpid(), new_pid);
			printf("---------------------------------------------------\n");
			break;
	}
	return 0;

}
