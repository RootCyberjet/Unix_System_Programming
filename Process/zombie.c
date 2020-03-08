#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

void main()
{
	int pid, exit_stat;
	int exit_val = 13;
	

	pid = fork();

	if(pid == 0)
	{
		printf("Child process died...\n");
		exit(exit_val);
	}
	sleep(20);
	if(pid > 0)
	{
		wait(&exit_stat);
		printf("\n\nI'm parent process...\n");
		printf("Child died with exit status %d\n",WEXITSTATUS(exit_stat));
		printf("Byeeee\n\n");
		exit(0);
	}
}
