#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMIT 30
struct myLinkedList {
	char word[LIMIT];
	struct myLinkedList* next;
};
int main() {

	struct myLinkedList* yourWords = NULL;
	struct myLinkedList* temp = NULL;
	yourWords = (struct myLinkedList*)malloc(sizeof(struct myLinkedList));
	printf("input word, word, word,... enter\n");
	int done = 0;
	while (done == 0) {
		char newword[LIMIT] ="";
		for (int i = 0; i < LIMIT; i++)//This loop gets one word and filters spaces
		{
			char tempStr[2] = "";
			tempStr[0] = getchar();
			if (tempStr[0] == '\n') //ends on \n character
			{
				i = LIMIT;
				done = 1;
			}
			else if(tempStr[0] == ',')
			{
				i = LIMIT;
			}
			else if(tempStr[0] != ' ')
			{
				strcat(newword, tempStr);
			}
		}
		struct myLinkedList* tempStruct = (struct myLinkedList*)malloc(sizeof(struct myLinkedList));   //next 4 lines add to the front of the linked list.
		strcpy(tempStruct->word, newword);
		tempStruct->next = yourWords;
		yourWords = tempStruct;
	}
	while (yourWords->word!= NULL) {   //Displays each piece of the linked list
		printf("%s\n", yourWords->word);
		yourWords = yourWords->next;
	}

  return 0;
}