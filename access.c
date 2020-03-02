#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void main(int argc, char* argv[])
{
	int i;

	if(argc == 1)
	{
		printf("No arguments found...\n");
		exit(1);
	}

	for(i=1;i<argc;i++)
	{
		printf("%s : ",argv[i]);

		if((access(argv[i],F_OK)) == -1)
		{
			printf("File does't exist\n");
			continue;
		}
		if((access(argv[i],R_OK)) == -1)
		{
			printf("Not readable\t");
		}
		else
		{
			printf("Readable\t");
		}
		if((access(argv[i],W_OK)) == -1)
		{
			printf("Not writable\t");
		}
		else
		{
			printf("Writable\t");
		}
		if((access(argv[i],X_OK)) == -1)
		{
			printf("Not executable\t");
		}
		else
		{
			printf("Executable\t");
		}
		printf("\n");
	}
	exit(0);
}


















