#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h> /* Necessary because errno value used */
#include <stdlib.h> /* Necessary for exit() */
void error(char* msg)
{
	printf("%s: %s\n", msg, errno);
	exit(1);
}
int main()
{
	pid_t pid;
	int counter = 0;
	pid = fork();
	if (pid == -1) error("Cannot fork() process!!");
	if (pid == 0)
	{ /* child process */
		printf("\n I am the child! My pid is %d\n", getpid());
		sleep(8);
		printf("I am the child and I am finishing only now\n");
			
	}
	else if (pid > 0)
	{ /* parent process */
		sleep(5);
		printf("I'm still Here! My PID is %d and my child's is %d\n",getpid(),pid);
	}
	return 0;
}