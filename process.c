#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void main()
{
	printf("PID : %4d, PPID : %4d\n",getpid(),getppid());
	printf("UID : %4d, GID : %4d\n",getuid(),getgid());
	printf("EUID : %4d, EGID : %4d\n",geteuid(),getegid());
	exit(0);
}
