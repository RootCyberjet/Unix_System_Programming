#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define TRUE 1

void main(int argc, char* argv[])
{
	int n;

	if(argc <= 1)
	{
		printf("No arguments found...\n");
		exit(1);
	}

	while(TRUE)
	{

		printf("1. For execl \n");
		printf("2. For execv \n");
		printf("3. For quit\n");
		printf("\nEnter your choice : ");
		scanf("%d",&n);

		switch(n)
		{
			case 1:
				{
					execl("/usr/bin/ls","ls","/home/shiba",(char*) 0);
					printf("execl error\n");
					break;
				}
			case 2:
				{
					execv(argv[1], &argv[2]);
					printf("execv error\n");
					break;
				}
			case 3:
				{
					exit(0);
					break;
				}
			default:
				printf("Invalid options...\n\n");
		}
	}
	exit(0);
}
