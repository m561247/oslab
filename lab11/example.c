
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>



void catch_int_2(int sig_num) {
	printf("I am fine!\n");
}

int main() {
	signal(SIGINT, catch_int_2);
	signal(SIGINT, SIG_DFL);

	while(1) pause() ;

	return 0;
}
