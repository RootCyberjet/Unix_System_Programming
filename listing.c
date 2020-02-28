#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>				/* For dirent structure */

void main(int argc, char* argv[])		/* Command line arguments */
{
	DIR *dir;				/* Define a pointer of type DIR which holds address of directory if it open */ 
	struct dirent *direntry;		/* Define a pointer of type struct dirent which holds address of inodes, names */

	if(argc != 2)				/* Simple verification on arguments given in command line */
	{
		if(argc < 2)
			printf("No arguments found...\n");
		if(argc > 2)
			printf("Too many arguments...\n");
		exit(1);
	}


	if((dir = opendir(argv[1])) == NULL)	/* If opendir returns null pointer then exit, so directory must exist and readable */
	{
		perror("Directory");		/* To print actual reason why program exits. */
		exit(1);
	}

	while((direntry = readdir(dir)) != NULL)	/* To read the directory structure */
	{
		printf("%10d  %s\n",direntry->d_ino,direntry->d_name); /* extract data from dirent structure, mainly inodes & names */
	}

	closedir(dir);				/* Close all opened directory */
	exit(0);				/* For successfully execution */
}
