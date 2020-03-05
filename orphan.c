#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void main()
{
	switch(fork())
	{
		case -1:
			{
				perror("fork");
				break;
			}
		case 0:
			{
				sleep(4);
				printf("I'm the child process...\n");
				printf("My PID : %d and PPID : %d\n",getpid(),getppid());
				exit(0);
				break;
			}
		default:
			{
				printf("I'm the parent process...\n");
				printf("I'm terminated\n");
				exit(0);
			}
	}
}
