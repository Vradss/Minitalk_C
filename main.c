#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <signal.h>

# include "printf.h"


int main(int argc , char *argv[])
{
	int pid = fork();
	fork();

	if (pid == -1)
		return 1;
	
	if (pid == 0)
	{
		while(1)
		{
			printf("VRADISSS\n  = %d", getpid());
			usleep(50000);
		}
	}
	else
		sleep(1);
		kill(pid, SIGKILL);
		wait(NULL);
	return 0;
}