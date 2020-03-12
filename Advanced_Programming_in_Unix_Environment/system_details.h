#include<sys/utsname.h>
#include<stdlib.h>
#include<stdio.h>

void utsname(void)
{
	struct utsname data;

	if(uname(&data) == -1)
	{
		perror("uname_error");
		exit(1);
	}

	printf("Name of the operating system 		: %s\n",data.sysname);
	printf("Name of the the node 			: %s\n",data.nodename);
	printf("Current release of operating system 	: %s\n",data.release);
	printf("Current version of the release 		: %s\n",data.version);
	printf("Name of hardware type 			: %s\n",data.machine);
	printf("\n");
	exit(0);
}
