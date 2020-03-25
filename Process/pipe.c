#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>
void main()
{
	int n, fd[2],stat;
	char buf[100];

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
				exit(1);
			}
		case 0:
			{
				printf("I'm child process...\n");
				close(fd[1]);
				n = read(fd[0], buf, 100);
				write(STDOUT_FILENO, buf, n);
				break;
			}
		default:
			{
				printf("I'm parent process...\n");
				printf("Child's exit status : %d\n",WEXITSTATUS(stat));
				close(fd[0]);
				write(fd[1], "Hey I'm RootCyberjet...\n", 24);
			}
	}
	exit(0);
}
