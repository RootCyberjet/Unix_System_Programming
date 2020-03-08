#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void main()
{
	pid_t pid;
	int x = 13;

	printf("Before fork\n");
	pid = fork();

	if(pid > 0)
	{
		sleep(1);
		printf("PARENT -- PID : %d, PPID : %d, CHILD PID : %d, x = %d\n",getpid(),getppid(),pid,x);
	}
	else if(pid == 0)
	{
		printf("CHILD -- PID : %d, PPID : %d, x = %d\n",getpid(),getppid(),x+1);
	}
	else
	{
		printf("Fork error\n");
		exit(1);
	}
	printf("Both process continue from here\n");
	exit(0);
}
