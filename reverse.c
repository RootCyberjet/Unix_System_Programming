#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>

void main(int argc, char* argv[])
{
	int f;
	char ch;
	int size;

	if(argc == 1)
	{
		printf("No arguments found...\n");
		exit(1);
	}
	else if(argc > 2)
	{
		printf("Too many arguments...\n");
		exit(1);
	}
	else
	{
		f = open(argv[1],O_RDONLY);
		
		if(f == -1)
		{
			printf("File does not exist...\n");
			exit(1);
		}

		size = lseek(f, -1, SEEK_END);

		while((size--) >= 0)
		{
			read(f,&ch,1);
			write(STDOUT_FILENO, &ch, 1);
			size = lseek(f, -2, SEEK_CUR);
		}

		close(f);
		printf("\n");
	}
}

