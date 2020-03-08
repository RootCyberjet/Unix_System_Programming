#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>

void main()
{
	int fd[2],stat;

	if(pipe(fd) == -1)
	{
		perror("PIPE");
		exit(1);
	}

	switch(fork())
	{
		case -1:
			{
				printf("Forking error...\n");
				exit(2);
				break;
			}
		case 0:
			{
				close(fd[0]);
				dup2(fd[1],1);
				close(fd[1]);
				execlp("cat","cat","-n","/etc/passwd",(char*) 0);
				exit(3);
				break;
			}
		default:
			{
				wait(&stat);
				close(fd[1]);
				dup2(fd[0],0);
				close(fd[0]);
				execlp("grep","--color=auto","shiba",(char*) 0);
			}
	}
	exit(0);
}















