#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

void main()
{
	int f, exitval = 10;
	int exit_stat;
	f = open("foo.txt", O_WRONLY|O_CREAT, 0644);
	write(f,"I'm parent process\n",19);

	switch(fork())
	{
		case -1:
			{
				perror("fork");
				break;
			}
		case 0:
			{
				printf("I'm the child process :\n");
				printf("I'm exit with status is %d\n",exitval);
				write(f,"I'm child process\n",18);
				close(f);
				exit(exitval);
				break;
			}
		default:
			{
				wait(&exit_stat);
				printf("I'm the parent process :\n");
				write(f,"I'm parent process\n",19);
				close(f);
				printf("Child's exit status is %d\n",WEXITSTATUS(exit_stat));
				exit(0);
			}
	}
}
