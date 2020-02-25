#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>			/* for read, write, execute of file */
#include<sys/stat.h>			/* for permission setup */

#define BUFFER_SIZE 1024


void main(int argc, char* argv[])
{
	int f1,f2;			/* file descriptors for read and write */
	int n;				/* no of characters returned by read */
	char BUFFER[BUFFER_SIZE];	/* array in which read string stored */

	f1 = open(argv[1],O_RDONLY);	/* open an existing file in read mode */ 
	f2 = open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);	/* create a file with 644 permission
											   and open in write mode */
	while((n = read(f1, BUFFER, BUFFER_SIZE)) > 0)
	{
		write(f2, BUFFER, n);
	}

	close(f1);			/* close f1 file descriptor */
	close(f2);			/* close f2 file descriptor */

	exit(0);
}


