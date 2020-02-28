#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<sys/stat.h>

void main(int argc, char* argv[])
{
	struct stat data;

	if(argc != 2)
	{
		if(argc > 2)
			printf("Too many arguments...\n");
		else
			printf("No arguments found...\n");
		exit(1);
	}

	if((lstat(argv[1], &data)) == -1)
	{
		perror("No stat found");
		exit(1);
	}
	else
	{
		printf("File : %s\n",argv[1]);
		printf("Inode number : %d\n",data.st_ino);
		printf("Mode : %o\n",data.st_mode);
		printf("No. of hardlink : %d\n",data.st_nlink);
		printf("User ID : %d\n",data.st_uid);
		printf("Group ID : %d\n",data.st_gid);
		printf("Device ID : %d\n",data.st_rdev);
		printf("File size : %d\n",data.st_size);
		printf("Access time : %s",ctime(&data.st_atime));
		printf("Modification time : %s",ctime(&data.st_mtime));
		printf("Changing time of inode : %s",ctime(&data.st_ctime));
		printf("Blockes allocated : %d\n",data.st_blocks);
		printf("Preferred block size : %d\n",data.st_blksize);
	}
	exit(0);
}
