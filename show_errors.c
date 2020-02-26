#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main()
{
	int i;
	extern int sys_nerr;

	for(i=0;i<sys_nerr;i++)
	{
		printf("%d: %s\n",i,strerror(i));
	}
	printf("Number of errors available : %d\n",sys_nerr);
	exit(0);
}
