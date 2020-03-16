#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int global_var = 6;

void main()
{
	int var;
	pid_t pid;

	var = 88;
	printf("Before fork\n");

	if((pid = vfork()) < 0)
	{
		perror("Fork error");
		exit(1);
	}
	else if(pid == 0)
	{
		global_var++;
		var++;
		_exit(0);
	}
	printf("PID = %ld, global_var = %d, var = %d\n",(long)getpid(),global_var, var);
	exit(0);
}
