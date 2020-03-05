#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

void main(int argc, char* argv[])
{
	int f;

	if(argc != 2)
	{
		if(argc > 2)
			printf("Too many arguments...\n");
		else
			printf("No arguments found...\n");
		printf("Usage : command [file_name]\n");
		exit(1);
	}

	close(STDOUT_FILENO);
	
	f = open(argv[1], O_CREAT | O_WRONLY | O_TRUNC, 0600);
	execl("/usr/bin/ls","ls","-al","/etc",(char*) 0);
	printf("\nexecl error\n");
}
