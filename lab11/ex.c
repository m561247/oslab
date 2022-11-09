
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

void catch_int(int sig_num)
{
	printf("Hello signal %d;\n", sig_num);
}

int main()
{
	signal(SIGINT, catch_int);	
	while(1)
		pause();
	return 0;
}
