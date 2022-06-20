/* Program that counts capitals in an input. */
#define MAX 50
#define MIN 2
#include <stdio.h>
#include <stdlib.h>

int main() {
	int myInput;
	scanf("%i",&myInput);
	int num = (rand() % (MAX - MIN) + MIN);
	if (myInput !=num)
	{
		printf("Unlucky. %i %i", num, myInput);
		return 0;
	}
	printf("Correct!");
  return 0;
}