/* Program that counts capitals in an input. */

#include <stdio.h>
#include <unistd.h>

int main()
{
	// try to run the "/sbin/ifconfig" program firstly
	execlp("/bin/ifconfig", "/sbin/ifconfig", NULL);
	//only gets here if failed
	execlp("ipconfig", "ipconfig", NULL);
	printf("Fail!");
	return 0;
   }