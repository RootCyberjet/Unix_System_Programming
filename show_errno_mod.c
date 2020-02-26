#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>
#include<errno.h>

void main(int argc, char* argv[])
{
	int fd;

	if(argc != 2)
	{
		if(argc > 2)
			printf("Too many arguments...\n");
		if(argc == 1)
			printf("No arguments found...\n");
	}

	if((fd = open(argv[1],O_RDONLY)) == -1)
	{
		fprintf(stderr,"%d : %s\n",errno,strerror(errno));
	}

	if((fd = open("/etc/shadow",O_RDONLY)) == -1)
	{
		fprintf(stderr,"%d : %s\n",errno,strerror(errno));
	}

	if((fd = open(argv[1],O_RDONLY | O_CREAT | O_EXCL, 0766)) == -1)
	{
		fprintf(stderr,"%d : %s\n",errno,strerror(errno));
	}
}
