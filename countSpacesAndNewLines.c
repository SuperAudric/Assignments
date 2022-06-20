/* Program that counts spaces and new lines in an input. */

#include <stdio.h>

void test() {
	printf("This was my testing");
}

int main() {
	int a = 0;
	int e = 0;
	int i = 0;
	int o = 0;
	int u = 0;
	char myChar = 'a';
	do {
		myChar = getchar();
		if (myChar == 'a') //finds input spaces
		{
			a++;
		}
		if (myChar == 'e')//finds input new lines
		{
			e++;
		}
		if (myChar == 'i')//finds input new lines
		{
			i++;
		}
		if (myChar == 'o')//finds input new lines
		{
			o++;
		}
		if (myChar == 'u')//finds input new lines
		{
			u++;
		}
	} while (myChar != EOF);//Ends when CTR + D is hit
	printf("Spaces: %i\n%i\n%i\n%i\n%i\n", a,e,i,o,u);
  return 0;
}