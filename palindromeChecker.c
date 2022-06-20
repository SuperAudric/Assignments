/* Program that counts capitals in an input. */
#define LIMIT 5
#include <stdio.h>

int main() {
	char myInput[LIMIT] = "Tempy";

	for (int i = 0; i < LIMIT; i++)
	{
		myInput[i] = getchar();
	}

	for (int i = 0; i < LIMIT; i++)
	{
		if (myInput[i] != myInput[LIMIT - i-1])
		{
			printf("This is not a palindrome.");
			return 0;
		}
	}
	printf("This is a palindrome.");
  return 0;
}