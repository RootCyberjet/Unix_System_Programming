/* This is a simple program on unlink system call */

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>


void main(int argc, char* argv[])
{
	if(argc != 2)
	{
		if(argc > 2)
			printf("Too many arguments...\n");
		else
			printf("No arguments found...\n");
		printf("Usage : command [file_path]\n");
		exit(1);
	}

	if(access(argv[1],F_OK) == -1)
	{
		perror("Existence of file");
		exit(1);
	}
	
	if(unlink(argv[1]) == -1)
	{
		perror("Can't unlink");
		exit(1);
	}
	
	printf("%s unlinked...Done\n",argv[1]);
}
