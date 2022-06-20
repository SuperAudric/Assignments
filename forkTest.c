#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h> // Necessary for errno
#include <stdlib.h> // Necessary for exit() 
void error(char* msg) //wrapper for error
{
	printf("%s: %s\n", msg, errno);
	exit(1);
}
int main()
{

	char studentID[] = "190359933"; //my studentID
	pid_t pid;
	pid = fork(); //splitprocess
	if (pid == -1) error("Cannot fork() process!!");
	if (pid == 0)
	{ // child process 
		int myProduct = 1;
		for (int i = 0;i < strlen(studentID); i++) {
			if (studentID[i] != '0') { //multiply all non-zero numbers
				myProduct *= studentID[i] - '0';
			}
		}
		printf("%i\n", myProduct);
			
	}
	else if (pid > 0)
	{ // parent process 
		int status;
		if ((pid = wait(&status)) < 0) error("wait");
		int mySum = 0;
		for (int i = 0;i < strlen(studentID); i++) {//add all numbers
			mySum += studentID[i] - '0';
		}
		printf("%i\n",mySum);
	}
	return 0;
}