/* Returns vertical bars of lengths of the 10 input numbers. */
#define LIMIT 10
#include <stdio.h>

int main() {
	int myInput[LIMIT];
	int max = 0;
	for (int i = 0; i < LIMIT; i++)
	{
		myInput[i] = getchar()- '0';
		if (myInput[i] > max) 
		{
			max = myInput[i];
		}
	}

	for (int y = max; y > 0; y--)
	{
		for (int x = 0; x < LIMIT; x++)
		{
			if (myInput[x] - y >= 0)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	
  return 0;
}