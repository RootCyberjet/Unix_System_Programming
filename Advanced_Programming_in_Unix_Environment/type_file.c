/* In this program we prints the type of file for each command line arguments */

#include<stdio.h>
#include<stdlib.h>		/* For exit() function */
#include<unistd.h>
#include<sys/stat.h>		/* For struct stat structure */


void main(int argc, char* argv[])
{
	int i;
	struct stat file;

	if(argc == 1)		/* Command-line input verification */
	{
		printf("No arguments found...\n");
		printf("Usage : command [file_name1] [file_name2] ... \n");
		exit(1);
	}

	for(i=1;i<argc;i++)	/* Take one argument at a time from command line ... */ 
	{			/* ... and print its type */
		if(lstat(argv[i],&file) == -1)
		{
			printf("lstat error in %s\n", argv[i]);
			perror("lstat");
			continue;
		}
		printf("******        TYPE OF %s        ******\n",argv[i]);
		printf("--------------------------------------------\n");
		if(S_ISREG(file.st_mode))
			printf("Regular File\n");
		else if(S_ISDIR(file.st_mode))
			printf("Directory\n");
		else if(S_ISCHR(file.st_mode))
			printf("Character special file\n");
		else if(S_ISBLK(file.st_mode))
			printf("Block special file\n");
		else if(S_ISFIFO(file.st_mode))
			printf("Pipe or FIFO\n");
		else if(S_ISLNK(file.st_mode))
			printf("Symbolic link\n");
		else if(S_ISSOCK(file.st_mode))
			printf("Socket file\n");
		printf("--------------------------------------------\n");
	}
	exit(0);
}
