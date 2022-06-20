#include <stdio.h> 



void printUpToX(int x) { //prints the values 1 up to but not including x
	int i = 1;
	do {
		printf("%i\n", i);
		i++;   
	} while (i < product);  //repeats once for each value up to x
}


int main() {
	int a = 9, b = 3, c = 3;  //each of the last 3 digits of my ID
	int product = a * b * c;  //finds product
	printUpToX(product); //runs the user defined function with the correct number
	return 0;
}