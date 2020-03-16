#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/times.h>
#include"pr_exit.h"


void command(char*);
void pr_times(clock_t, struct tms*, struct tms*);

void main(int argc, char* argv[])
{
	int i;
	setbuf(stdout,NULL);
	for(i=1;i<argc;i++)
		command(argv[i]);
	exit(0);
}

void command(char* str)
{
	struct tms start_time,end_time;
	clock_t start,end;
	int status;

	printf("\nCommand : %s\n",str);

	if((start = times(&start_time)) == -1)
	{
		perror("start time error");
		exit(1);
	}
	if((status = system(str)) == -1)
	{
		perror("system error");
		exit(1);
	}
	if((end = times(&end_time)) == -1)
	{
		perror("end time error");
		exit(1);
	}

	pr_times(end-start, &start_time, &end_time);
	pr_exit(status);
}

void pr_times(clock_t real, struct tms* start_time, struct tms* end_time)
{
	long clktck = 0;
	if(clktck == 0)
	{
		if((clktck = sysconf(_SC_CLK_TCK)) == -1)
		{
			perror("sysconf error");
			exit(1);
		}
	}

	printf("	real		:	%7.2f\n",real/(double)clktck);
	printf("	user		:	%7.2f\n",(end_time->tms_utime - start_time->tms_utime)/(double)clktck);
	printf("	sys		:	%7.2f\n",(end_time->tms_stime - start_time->tms_stime)/(double)clktck);
	printf("	child user	:	%7.2f\n",(end_time->tms_cutime - start_time->tms_cutime)/(double)clktck);
	printf("	child sys	:	%7.2f\n",(end_time->tms_cstime - start_time->tms_cstime)/(double)clktck);
	
}
