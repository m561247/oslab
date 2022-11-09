#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main() {
	printf("Real Uid = %d\n""Effective Uid = %d\n", getuid(), geteuid());
	return 0;
}
