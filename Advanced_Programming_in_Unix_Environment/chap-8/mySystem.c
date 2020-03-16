#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"pr_exit.h"


void main()
{
	int status;

	if((status = system("date")) == -1)
	{
		perror("system error");
		exit(1);
	}
	pr_exit(status);
	printf("\n");

	if((status = system("no_such_command")) == -1)
	{
		perror("system error");
		exit(1);
	}
	pr_exit(status);
	printf("\n");

	if((status = system("who; exit 10")) == -1)
	{
		perror("system error");
		exit(1);
	}
	pr_exit(status);

	exit(0);
}
