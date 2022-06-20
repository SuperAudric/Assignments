#define LIMIT 20
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE *filePointer= fopen("cities.txt", "r");
	char myString[255]="";
	char myOutput[1000]="";
	int myInt;
	if (filePointer == NULL)
	{
		printf("File not found");
		exit(0);
	}
	for (int i = 0;i < LIMIT;i++) {
		if(fscanf(filePointer, "%i%s", &myInt, myString)>1)
			if (myInt > 100) {
				strcat(myOutput, "\n");
				strcat(myOutput, myString);
			}
		//printf("%i:%s, %i\n", i+1, myString,myInt);
	}
	FILE* outFile = fopen("OUTPUT.txt", "w");
	fprintf(outFile, "%s", myOutput);
	fclose(filePointer);
	fclose(outFile);
	//printf(myOutput);
	return 0;
}