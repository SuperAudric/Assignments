/* Program that lets you guess a number. */
#define ADD(a,b) (a+b)
#define SUB(a,b) (a-b)
#define MLT(a,b) (a*b)
#define DIV(a,b) (a/b)
#include <stdio.h>
#include <stdlib.h>

int main() {
	int myInputVal1;
	char inputOp;
	int myInputVal2;
	scanf("%i%c%i",&myInputVal1,&inputOp, &myInputVal2);
	int ans = (inputOp == '+' ? ADD(myInputVal1,myInputVal2) : (inputOp=='-'?SUB(myInputVal1,myInputVal2):(inputOp=='*'?MLT(myInputVal1, myInputVal2):inputOp=='/'? DIV(myInputVal1, myInputVal2):0)));
	printf("\n%i\n",ans);
  return 0;
}