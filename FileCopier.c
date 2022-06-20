#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

#define LIMIT 20


void error(char* msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

int main()
{
    char myString = '\0';
    FILE* myInput = (FILE*)fopen("ToSee.txt", "r");
    FILE* myOutput = (FILE*)fopen("OUTPUT.txt", "w");
    while(fscanf(myInput, "%c", &myString)==1) {
        fprintf(myOutput,"%c",myString);
    }
    return 0;
}