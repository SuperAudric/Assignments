#define LIMIT 20
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char myString[255]="";
	char myOutput[1000]="";
	int myInt;
	for (int i = 0;i < LIMIT;i++) {
		if(scanf("%i%s", &myInt, myString)>1)
			if (myInt > 100) {
				strcat(myOutput, "\n");
				strcat(myOutput, myString);
			}
		//printf("%i:%s, %i\n", i+1, myString,myInt);
	}
	FILE* outFile = fopen("OUTPUT.txt", "w");
	fprintf(outFile, "%s", myOutput);
	fclose(outFile);
	printf(myOutput);
	return 0;
}