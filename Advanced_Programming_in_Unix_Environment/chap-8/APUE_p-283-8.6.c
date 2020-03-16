#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>


void main()
{
	int status;
	pid_t pid;

	if((pid = fork()) == -1)
	{
		perror("Forking error");
		exit(1);
	}
	else if(pid == 0)
	{
		printf("I'm child process...\n");
		printf("I'm terminated...\n\n");
		exit(1);
	}
	else
	{
		sleep(2);
		printf("The details of Zombie process is :\n");
		system("ps | grep defunct");
		sleep(10);
		wait(&status);
		printf("\nI'm parent process...\n");
		printf("I'm terminated...\n\n");
		exit(0);
	}
}
