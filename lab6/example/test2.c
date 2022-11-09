#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
	
	pid_t B = fork();

	if (B == 0) 
	{	
		pid_t C = fork();
		if (C == 0) {
			printf("I'm child process C\npid = %d, parentId = %d\n", getpid(), getppid());
		}
		if (C > 0) {
			wait(NULL);
			printf("I'm child process B\npid = %d , parentId = %d\n", getpid(), getppid());	
		}
	}
	if (B > 0)
	{
		pid_t D = fork();
		if (D ==0)
		{	
			printf("I'm child process D\npid = %d, parentId = %d\n", getpid(), getppid());
		}
		if (D > 0){
			pid_t E = fork();
			if (E == 0) {
				printf("I'm child process E\npid = %d, parentId = %d\n", getpid(), getppid());
			}
			if (E > 0) {
				wait(NULL);
				wait(NULL);
				wait(NULL);
				printf("I'm parent process A\npid = %d, parentId = %d\n", getpid(), getppid());
			}
		}
	}	

	return 0;
}
