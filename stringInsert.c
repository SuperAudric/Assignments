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
	getchar();//removes the \n from the buffer after scanf

	char toBeAdded[LIMIT] = "";
	printf("Input Addition:\n");
	for (int i = 0; i < LIMIT; i++)
	{
		char temp = getchar();
		if (temp == '\n') {
			i = LIMIT;
		}
		else{
			toBeAdded[i] = temp;
		}
	}


	char output[LIMIT]="";
	for (int i = 0; i < LIMIT; i++)
	{
		if (i <= pos-1)
		{
			char temp[2];
			temp[0]= myInput[i];
			strcat(output, temp);
		}
		if (i == pos - 1)
		{
			strcat(output, toBeAdded);
		}
		if (i > pos - 1)
		{
			char temp[2];
			temp[0] = myInput[i];
			strcat(output, temp);
		}
	}
	printf("\n%s",output);
  return 0;
}