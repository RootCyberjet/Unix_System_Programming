#include<stdio.h>
#include<utime.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>

void main(int argc, char* argv[])
{
	struct stat statbuf;
	struct utimbuf times;
	int fd;

	if(argc != 3)
	{
		if(argc > 3)
			printf("Too many arguments...\n");
		if(argc < 3)
			printf("Few arguments...\n");
		printf("Usage : command [file1_name] [file2_name]\n");
		exit(1);
	}

	if(access(argv[1],F_OK) == -1)
	{
		printf("File %s does't exist...\n",argv[1]);
		exit(1);
	}

	if(lstat(argv[1],&statbuf) == -1)
	{
		perror("lstat");
		exit(2);
	}
	
	int perm = statbuf.st_mode & ~S_IFMT;
	time_t mod = statbuf.st_mtime;
	time_t accs = statbuf.st_atime;

	if(fd = (open(argv[2],O_WRONLY | O_CREAT, perm)) == -1)
	{
		printf("Error in file creation...\n");
		exit(3);
	}
	close(fd);

	times.actime = accs;
	times.modtime = mod;

	if(utime(argv[2], &times) == -1)
	{
		perror("utime");
		exit(4);
	}
	exit(0);
}












