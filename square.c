/* Returns vertical bars of lengths of the 10 input numbers. */
#include <stdio.h>

int main() {
	int size = 10;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	
  return 0;
}