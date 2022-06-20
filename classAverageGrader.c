/* Program that lets you guess a number. */
#define ADD(a,b) (a+b)
#define SUB(a,b) (a-b)
#define MLT(a,b) (a*b)
#define DIV(a,b) (a/b)
#include <stdio.h>
#include <stdlib.h>
 
struct student {
	char name[30];
	int number;
	int marks[6];
};

int main() {
	struct student myClass[5] = { { "Bob", 1,{5,2,2,3,0,0} },
								{"Frida",2,{1,2,3,4,5,6}},
								{"Fridouble",22,{1,2,3,4,5,6}},
								{"Fritripple",333,{1,2,3,4,5,6}},
								{"Friquad",4,{1,2,3,4,5,6}} };
	for (int i =0; i<sizeof(myClass)/sizeof(myClass[0]);i++)
	{
		int size = sizeof(myClass[i].marks) / sizeof(myClass[i]).marks[0];
		float count = 0;
		for (int j = 0; j < size ; j++) {
			count += myClass[i].marks[j];
		}
		printf("Name: %s Average: %f\n", myClass[i].name, count/size);
	}
	return 0;
}