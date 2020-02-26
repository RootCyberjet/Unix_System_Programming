#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#define PATH 100

void main(int argc, char* argv[])
{
	char old_dir[PATH], new_dir[PATH];
	
	if(argc != 2)
	{
		if(argc == 1)
			printf("No argument found...\n");
		else
			printf("Too many arguments...\n");
		exit(1);
	}
	getcwd(old_dir,PATH);
	printf("pwd : %s\n",old_dir);

	chdir(argv[1]);
	
	getcwd(new_dir,PATH);
	printf("pwd : %s\n",new_dir);

	exit(0);
}
