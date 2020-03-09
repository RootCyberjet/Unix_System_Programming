/* Programm to copy standard input to standard output */

#include<stdio.h>
#include<stdlib.h>		/* For exit() function */
#include<unistd.h>

void main()
{
	int n;
	char buffer[1024];

	while((n = read(STDIN_FILENO, buffer, 1024)) > 0)	/* n bytes read from STDIN */
	{
		if(write(STDOUT_FILENO, buffer, n) != n)	/* Write n bytes in STDOUT which have been alredy read */
		{
			perror("Write error");			/* Throwing error if return from read and write are not same */
			exit(1);
		}
	}
	if(n < 0)
	{
		perror("Reading error");			/* Throwing error if can't read from STDIN */
		exit(1);
	}
	exit(0);
}
