/* Program that counts spaces and new lines in an input. */

#include <stdio.h>

int main() {
	int spaces = 0, Newlines = 0;
	char myChar = 'a';
	do {
		myChar = getchar();
		if (myChar == ' ') //finds input spaces
		{
			spaces++;
		}
		if (myChar == '\n')//finds input new lines
		{
			Newlines++;
		}
	} while (myChar != EOF);//Ends when CTR + D is hit
	printf("Spaces: %i, Lines: %i\n", spaces,Newlines);
  return 0;
}