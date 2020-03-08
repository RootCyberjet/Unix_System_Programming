#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

void main(int argc, char* argv[])
{
	int f1,f2;

	if(argc == 1)
	{
		printf("Usage : command [input_file] [output_file] [shell_command]\n");
		exit(1);
	}
	
	f1 = open(argv[1],O_RDONLY);
	f2 = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC, 0644);

	close(STDIN_FILENO);
	dup(f1);
	close(STDOUT_FILENO);
	dup(f2);

	execvp(argv[3], &argv[3]);
	printf("\nexecvp error\n\n");
}
