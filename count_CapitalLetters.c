/* Program that counts capitals in an input. */

#include <stdio.h>

int main() {
	int capitals = 0;
	char myChar = 'a';
	do {
		myChar = getchar();
		if (myChar >= 'A' && myChar <='Z') //Checks if letter is in the range of capital alphabet letters
		{
			capitals++;
		}
	} while (myChar != EOF);//Ends when CTR + D is hit
	printf("Capitals: %i", capitals);
  return 0;
}