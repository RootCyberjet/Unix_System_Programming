#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>

void main(int argc, char* argv[])
{
	int x = 100;
	char newdir[100];

	if(argc != 2)
	{
		if(argc > 2)
			printf("Too many arguments...\n");
		else
			printf("No arguments found...\n");
		printf("Usage : command [dir_path]\n");
		exit(1);
	}

	switch(fork())
	{
		case -1:
			{
				perror("fork");
				exit(1);
			}
		case 0:
			{
				printf("I'm child process :\n");
				printf("Initial value of x = %d\n",x);
				printf("Modified value of x = %d\n",x+1);
				printf("The original PATH : %s\n",getenv("PATH"));
				setenv("PATH",".",1);
				printf("The new value of PATH : %s\n",getenv("PATH"));
				if(chdir(argv[1]) == -1)
					perror("Change_in_directory");
				else
				{
					getcwd(newdir,100);
					printf("Current directory is : %s\n",newdir);
				}
				break;
				exit(0);
			}
		default:
			{
				sleep(3);
				printf("\n\nI'm parent process :\n");
				printf("Value of x = %d\n",x);
				getcwd(newdir,100);
				printf("Current directory is : %s\n",newdir);
				printf("The PATH value is : %s\n",getenv("PATH"));
				exit(0);
			}
	}
}


















