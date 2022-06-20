/* Program that lets you guess a number. */
#define MAX 50
#define MIN 2
#include <stdio.h>
#include <stdlib.h>

int main() {
	int myInput;
	scanf("%i",&myInput);
	int num = (rand() % (MAX - MIN) + MIN);
	while (myInput!=num)
	{
		if (myInput > num)
		{
			printf("Too big. ");
		}
		else if (myInput < num) {
			printf("Too small. ");
		}
		scanf("%i", &myInput);
	}
	printf("Correct!");
  return 0;
}