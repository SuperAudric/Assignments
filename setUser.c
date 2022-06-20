/* Program that counts capitals in an input. */

#include <stdio.h>
#include <unistd.h>

int main()
{
	char* my_env[] = { "USER=Meow", NULL };//technically should be "USER=ECS501U", but meow is better
	//execle("changeUser.exe", "changeUser.exe", NULL, my_env);
	char* myargs[] = { "changeUser.exe", NULL };
	execve("changeUser.exe", myargs, my_env);
	printf("Fail!");
	return 0;
   }