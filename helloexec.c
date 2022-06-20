#include <stdio.h>
#include <unistd.h>
int main(int argc, char* argv[])
{
	int i;
	printf("\nThis is my HelloExec program:");
	printf("\nMy PID is %d", getpid());
	printf("\nMy arguments are: ");
	for (i = 0; i < argc; i++)
		printf("%s, ", argv[i]);
	printf("\n");
	return 0;
}