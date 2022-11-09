#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<signal.h>


void mysighand(int no)
{
	printf("Hello world\n");
	sleep(3);
	printf("wake up\n");
}




int main(int argc, const char* argv[])
{

	struct sigaction act;
	act.sa_flags = 0;
	sigaddset(&act.sa_mask, SIGQUIT);
	sigemptyset(&act.sa_mask);
	act.sa_handler = mysighand;
	sigaction(SIGINT, &act, NULL);

//	struct sigaction act;

//	sigaction(SIGINT, NULL, &act);
//	if (act.sa_handler == SIG_DFL)
//	{
	//	act.sa_handler = SIG_IGN;
//		act.sa_handler = mysighand;
//		sigaction(SIGINT, &act, NULL);
//	}
	while(1) pause();

	return 0;
}
