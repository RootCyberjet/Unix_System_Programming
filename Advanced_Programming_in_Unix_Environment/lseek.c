/* Successful call to lseek returns the new file offset.
 * This technique can also be used to determine if a file
 * is capable of seeking. If the file is PIPE, FIFO, socket
 * etc then lseek returns an error(Illegal seek).
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


void main()
{
	if(lseek(STDIN_FILENO,0,SEEK_CUR) == -1)
	{
		perror("lseek");
		exit(1);
	}
	else
		printf("Seeking OK...\n");
	exit(0);
}
