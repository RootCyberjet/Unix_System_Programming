#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>

void main()
{
	pid_t pid;
	
	if((pid = fork()) == -1)
	{
		perror("1st forking error");
		exit(1);
	}
	else if(pid == 0)
	{
		if((pid = fork()) == -1)
		{
			perror("2nd forking error");
			exit(1);
		}
		else if(pid > 0)
			exit(0);
		sleep(2);
		printf("Second child, PPID = %ld\n",(long)getppid());
		exit(0);
	}
	if(waitpid(pid,NULL,0) != pid)
	{
		perror("Wait error");
		exit(1);
	}
	exit(0);
}
