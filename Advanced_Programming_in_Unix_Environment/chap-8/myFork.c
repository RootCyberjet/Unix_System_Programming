#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int global_var = 6;
char buffer[] = "A write to stdout\n";

void main()
{
	int var;
	pid_t pid;

	var = 88;
	if(write(STDOUT_FILENO, buffer, sizeof(buffer)-1) != sizeof(buffer)-1)
	{
		perror("Write error");
		exit(1);
	}
	printf("Before fork\n");

	if((pid = fork()) < 0)
	{
		perror("Fork error");
		exit(1);
	}
	else if(pid == 0)
	{
		global_var++;
		var++;
	}
	else
		sleep(2);
	printf("PID = %ld, global_var = %d, var = %d\n",(long)getpid(),global_var, var);
	exit(0);
}
