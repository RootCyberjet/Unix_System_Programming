#include<stdio.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

void main(int argc, char* argv[])
{
	int fd;
	char buf1[] = "shiba";
	char buf2[] = "biswas";

	if(argc != 4)
	{
		if(argc > 4)
			printf("Too many arguments...\n");
		else
			printf("Some arguments are missing...\n");
		printf("Usage : command [file_name] [string1] [string2]\n");
		exit(1);
	}

	if(fd = (open(argv[1], O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
	{
		perror("File_creation");
		exit(2);
	}
	
	if(write(fd, buf1, 5) != 5)
	{
		perror("Error_:_Writing_first_string");
		exit(3);
	}

	if(lseek(fd,184,SEEK_SET) == -1)		/* Choosing random offset */
	{
		perror("lseek");
		exit(4);
	}
	
	if(write(fd, buf2, 6) != 6)
	{
		perror("Error_:_Writing_second_string");
		exit(5);
	}
	
	close(fd);
	exit(0);
}

