#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define LIMIT 20
int main()
{
    char initials[LIMIT] = ""; //declare variables to hold a students scores
    double theirGrade = 0;
    FILE* myOutput = (FILE*)fopen("EDU.Finals.txt", "w");// opens the output file for writing. Uses .txt so as to be a character file
    for(int i =0;i<33;i++) {
        scanf("%s %lf", &initials, &theirGrade); //get information
        fprintf(myOutput,"%s %0.1lf\n", initials,theirGrade); //store in file
    }
    return 0;
}