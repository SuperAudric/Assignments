#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h> /* Necessary because errno value used */
#include <stdlib.h> /* Necessary for exit() */
#include <sys/wait.h>
void error(char* msg)
{
	printf("%s: %s\n", msg, errno);
	exit(1);
}
int main()
{
	int status;
	pid_t pid;
	int counter = 0;
	pid = fork();
	if (pid == -1) error("Cannot fork() process!!");
	if (pid == 0)
	{ /* child process */
		printf("\n I am the child! My pid is %d\n", getpid());
	}
	else if (pid > 0)
	{ /* parent process */
		if ((pid = wait(&status)) < 0) error("wait");
		printf("I'm still Here!\n");
	}
	return 0;
}