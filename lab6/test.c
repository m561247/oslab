#include<stdio.h>
#include<unistd.h>

int global = 10;
int main()
{
	pid_t new_pid;
	
	 fork();
	printf("print : pid = %d\n",getpid());
	 fork();
	printf("print : pid = %d\n",getpid());
	 fork();	
	printf("print : pid = %d\n",getpid());
	

	return 0;
}


