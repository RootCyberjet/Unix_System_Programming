#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include"pr_exit.h"
void main()
{
	pid_t pid;
	int status;

	if((pid = fork()) == -1)
	{
		perror("1st Forking error");
		exit(1);
	}
	else if(pid == 0)
		exit(7);

	if(wait(&status) != pid)
	{
		perror("1st Wait error");
		exit(1);
	}
	pr_exit(status);

	if((pid = fork()) == -1)
	{
		perror("2nd Forking error");
		exit(1);
	}
	else if(pid == 0)
		abort();

	if(wait(&status) != pid)
	{
		perror("2nd Wait error");
		exit(1);
	}
	pr_exit(status);

	if((pid = fork()) == -1)
	{
		perror("3rd Forking error");
		exit(1);
	}
	else if(pid == 0)
		status /= 0;

	if(wait(&status) != pid)
	{
		perror("3rd Wait error");
		exit(1);
	}
	pr_exit(status);
	exit(0);
}
