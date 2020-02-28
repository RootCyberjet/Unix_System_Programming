#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<sys/types.h>
#include<dirent.h>				/* For dirent structure */

void main(int argc, char* argv[])		/* Command line arguments */
{
	DIR *dir;				/* Define a pointer of type DIR which holds address of directory if it open */ 
	struct dirent *direntry;		/* Define a pointer of type struct dirent which holds address of inodes, names */
	struct stat data;			/* Define a variable of type stuct stat */
	mode_t fileType,filePerm;

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
		perror("Directory");		/* To print actual reason why program exits */
		exit(1);
	}

	if((chdir(argv[1])) == -1)		/* Change directory before reading */
	{
		perror("Can't change directory");
		exit(1);
	}

	while((direntry = readdir(dir)) != NULL)	/* To read the directory structure */
	{
		if(lstat(direntry->d_name, &data) == -1)/* To analysis all information of each entry */
		{
			perror("No stat");
			continue;
		}

		if(S_ISDIR(data.st_mode))		/* To check its directory or not */
		{
			fileType = data.st_mode & S_IFMT;	/* Extract first 4 bits from 16 bits permissions */ 
			filePerm = data.st_mode & ~S_IFMT;	/* Entract remaining 12 bits from 16 bits permissions */
			printf("%o\t%o\t%s\n",fileType,filePerm,direntry->d_name);
		}
	}

	closedir(dir);				/* Close all opened directory */
	exit(0);				/* For successfully execution */
}
