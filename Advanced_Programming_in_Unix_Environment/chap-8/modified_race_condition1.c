/* We discuss this program after signal handling chapter */

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


void charatatime(char* str)
{
	char* ptr;
	int c;
	setbuf(stdout, NULL);
	for(ptr=str; (c = *ptr++) != 0; )
		putc(c,stdout);
}

void main()
{
	pid_t pid;
	TELL_WAIT();

	if((pid = fork()) == -1)
	{
		perror("Forking error");
		exit(1);
	}
	else if(pid == 0)
	{
		WAIT_PARENT();
		charatatime("output from child\n");
	}
	else
	{
		charatatime("OUTPUT FROM PARENT\n");
		TELL_CHILD(pid);
	}
	exit(0);
}
