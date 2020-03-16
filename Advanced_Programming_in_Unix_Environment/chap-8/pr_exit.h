#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>

void pr_exit(int status)
{
	if(WIFEXITED(status))
		printf("Normal termination, exit status = %d\n",WEXITSTATUS(status));
	else if(WIFSIGNALED(status))
		printf("Abnormal termintion, signal number = %d%s\n",WTERMSIG(status),
#ifdef WCOREDUMP
				WCOREDUMP(status)?" (core file generated)" : ""
#endif
	"");
	else if(WIFSTOPPED(status))
		printf("Child stopped, signal number = %d\n",WSTOPSIG(status));
}
