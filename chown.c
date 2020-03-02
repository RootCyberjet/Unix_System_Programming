#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void main(int argc, char* argv[])
{
	if(argc != 4)
	{
		if(argc > 4)
			printf("Too many arguments...\n");
		if(argc < 4)
			printf("Few arguments...\n");
		printf("Usage : command [file_name] [user_id] [group_id]\n");
		exit(1);
	}

	if(chown(argv[1],atoi(argv[2]),atoi(argv[3])) == -1)
	{
		perror("chown");
		exit(1);
	}
	exit(1);
}
