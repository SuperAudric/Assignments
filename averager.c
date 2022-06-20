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
	double std_grades[3][4] = { {7.7, 6.8, 8.6, 7.3},
								{9.6, 8.7, 8.9, 7.8},
								{7.0, 9.0, 8.6, 8.1} };
	for (int i =0; i< 3;i++)
	{
		int size = sizeof(std_grades[i]) / sizeof(std_grades[i][0]);
		float count = 0;
		for (int j = 0; j < size ; j++) {
			count += std_grades[i][j];
		}
		printf("Student: %i Average: %f\n",i, count/size);
	}
	return 0;
}