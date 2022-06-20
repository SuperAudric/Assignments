#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMIT 30
struct myLinkedList {
	int data;
	struct myLinkedList* next;
};

struct myLinkedList* push(struct myLinkedList* myStack, int myNum)//Adds to linked list
{
	struct myLinkedList* tempStruct = (struct myLinkedList*)malloc(sizeof(struct myLinkedList));   //next 4 lines add to the front of the linked list.
	tempStruct->data =myNum;
	tempStruct->next = myStack;
	myStack = tempStruct;
	return myStack;
}

struct myLinkedList* pop(struct myLinkedList* myStack) {//removes top layer of stack
	return myStack->next;
}

void printStack(struct myLinkedList* myStack) {
	while ((myStack->next != NULL)& (myStack->data!=-1)) {   //Displays each piece of the linked list
		printf("%i\n", myStack->data);
		myStack = pop(myStack);
	}
}

int main() {
	struct myLinkedList* yourStack = NULL;
	yourStack = (struct myLinkedList*)malloc(sizeof(struct myLinkedList));
	yourStack->data = -1;//marks end of chain
	printf("a to add, r to remove, enter to end\n");
	int done = 0;
	while (done == 0) {
		for (int i = 0; i < LIMIT; i++)//This loop gets one letter and processes it 
		{
			char tempStr[2] = "";
			tempStr[0] = getchar(); //stored user input, about to be processed
			if (tempStr[0] == '\n') //ends when user inputs \n character
			{
				i = LIMIT;
				done = 1;
			}
			else if (tempStr[0] == 'a')
			{
				int tempInt = rand();
				yourStack = push(yourStack,tempInt);
				printStack(yourStack);
				printf("\n");
			}
			else if (tempStr[0] == 'r')
			{
				yourStack=pop(yourStack);
				printStack(yourStack);
			}
		}
	}
	return 0;
}