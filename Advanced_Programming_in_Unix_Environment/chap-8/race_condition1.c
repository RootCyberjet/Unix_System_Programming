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

	if((pid = fork()) == -1)
	{
		perror("Forking error");
		exit(1);
	}
	else if(pid == 0)
	{
		charatatime("output from child\n");
	}
	else
	{
		charatatime("OUTPUT FROM PARENT\n");
	}
	exit(0);
}
