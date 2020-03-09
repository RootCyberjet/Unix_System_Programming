/* This is simple program on rename() system call */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void main(int argc, char* argv[])
{
	if(argc != 3)
	{
		if(argc > 3)
			printf("Too many arguments...\n");
		else
			printf("No arguments found...\n");
		printf("Usage : command [old_name] [new_name]\n");
		exit(1);
	}
	
	if(rename(argv[1],argv[2]) == -1)
	{
		perror("Error in rename");
		exit(1);
	}
	printf("Renaming done...\n");
	exit(0);
}
