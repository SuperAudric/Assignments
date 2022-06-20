/* Program that counts capitals in an input. */
#define LIMIT 50
#include <stdio.h>
#include <string.h>

int main() {
	char myInput[LIMIT] = "";
	printf("Input word:\n");
	for (int i = 0; i < LIMIT; i++)
	{
		myInput[i] = getchar();
		if (myInput[i] == '\n') {
			i = LIMIT;
		}
	}
	printf("Position to remove:\n");
	int pos;
	scanf("%i", &pos);
	char output[LIMIT]="";
	for (int i = 0; i < LIMIT; i++)
	{
		if (i != pos-1)
		{
			char temp[2];
			temp[0]= myInput[i];
			strcat(output, temp);
		}
	}
	printf("\n%s",output);
  return 0;
}