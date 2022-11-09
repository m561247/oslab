#include<stdio.h>
#include<unistd.h>

int global = 10;
int main()
{
	pid_t new_pid;
	
	int local = 10;
	new_pid = fork();
	if (new_pid == 0) {
		printf("I'm child process\n");
		printf("pid : %d\tparent id : %d\n", getpid(), getppid());
		printf("global = %d, local = %d\n", global, local);
		global++; local++;
	} else {
		printf("I'm parent process\n");
		printf("pid : %d\tparent id : %d\n", getpid(), getppid());
		printf("global = %d, local = %d\n", global, local);
			
	}

	printf("Finally print : pid = %d, parent id = %d,  global = %d, local = %d\n",getpid(), getppid(), global, local);
	return 0;
}


