/* Program illustrating some bitwise operators in C. */

#include <stdio.h>

int main() {
  int a = 9, b = 12; // in binary: 1001, 1100
  int numBits = 1;
	
  /* Output of bitwise AND is 1 if the corresponding bits of all operands is 1.
     If either bit of an operand is 0, the result of corresponding bit is evaluated to 0. */
  printf("Output of bitwise AND = %d\n", a&b); // Will print value 8.
    
  /* Output of bitwise OR is 1 if at least one corresponding bit of two operands is 1. */
  printf("Output of bitwise OR = %d\n", a|b); // Will print value 13.
	
  /* Left shift operator shifts all bits towards left by the number of specified bits. */
  printf("Output of left shift operator (by %d bit(s)) = %d", numBits, a<<numBits); // Will print value 18.
	
  return 0;
}