#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>


void main(int argc, char* argv[])
{
	int f1,f2;
	int exit_stat;

	if(argc == 1)
	{
		printf("Usage : command [input_file] [output_file] [shell_command]\n");
		exit(0);
	}

	if(fork() == 0)
	{
		printf("I'm the child process....\n\n");
		f1 = open(argv[1], O_RDONLY);
		if(f1 == -1)
		{
			printf("Unable to open for reading....\n");
			exit(1);
		}
		f2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0600);
		if(f2 == -1)
		{
			printf("Unable to open for writing....\n");
			exit(2);
		}
		dup2(f1,0);
		dup2(f2,1);
		
		execvp(argv[3], &argv[3]);
		printf("\n\nError to execute execvp\n");
	}
	else
	{
		wait(&exit_stat);
		printf("Parent says...\n");
		printf("Child's exit status is %d\n\n",WEXITSTATUS(exit_stat));
	}
	exit(0);
}
