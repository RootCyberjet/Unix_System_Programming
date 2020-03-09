/* This program takes a single command-line argument tht specifies a file
 * descriptor and prints a description of selected file flags for that descriptor */

#include<stdio.h>
#include<fcntl.h>		/* For fcntl() system call and file flags */
#include<unistd.h>
#include<stdlib.h>

void main(int argc, char* argv[])
{
	int val;
	
	if(argc != 2)		/* Varification of command-line input */
	{
		if(argc > 2)
			printf("Too many arguments...\n");
		else
			printf("No arguments found...\n");
		printf("Usage : command [file_descriptor]\n");
		exit(1);
	}
	
	if((val = fcntl(atoi(argv[1]), F_GETFL, 0)) == -1)	/* Returns the file status flags if succesful */
	{
		perror("fcntl");
		exit(1);
	}

	switch(val & O_ACCMODE)					/* Extract access modes from val variable */
	{
		case O_RDONLY:
			printf("Read only\n");
			break;
		case O_WRONLY:
			printf("Write only\n");
			break;
		case O_RDWR:
			printf("Read & Write modes\n");
			break;
		default:
			printf("*** Unknown access mode ***\n");
	}
	if(val & O_APPEND)
		printf("Append Mode\n");
	if(val & O_NONBLOCK)
		printf("Non-blocking Mode\n");
	if(val & O_SYNC)
		printf("Synchronous writes\n");
	exit(0);
}

