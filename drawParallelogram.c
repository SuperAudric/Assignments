/* Returns vertical bars of lengths of the 10 input numbers. */
#include <stdio.h>

int main() {
	int size = 10;
	for (int i = 0; i < size*3; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i >= j && (i-2*size<j||i<2*size)) {
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