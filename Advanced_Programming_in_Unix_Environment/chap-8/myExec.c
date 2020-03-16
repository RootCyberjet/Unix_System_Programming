#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>

char* env[] = {"USER=unknown","PATH=/home/shiba",NULL};

void main()
{
	pid_t pid;
	
	if((pid = fork()) == -1)
	{
		perror("Forking error");
		exit(1);
	}
	else if(pid == 0)
	{
		if(execle("/usr/bin/cat","cat","/etc/passwd",(char*)0,env) == -1)
		{
			perror("execle");
			exit(1);
		}
	}

	if(waitpid(pid,NULL,0) == -1)
	{
		perror("waitpid");
		exit(1);
	}

	if((pid = fork()) == -1)
	{
		perror("Forking error");
		exit(1);
	}
	else if(pid == 0)
	{
		if(execlp("/usr/bin/cat","cat","myExec.c",(char*)0) == -1)
		{
			perror("execlp");
			exit(1);
		}
	}
	exit(0);
}
