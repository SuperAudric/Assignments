/* Simple 'typewriter' program.
   Every set of characters is echoed once ENTER has been pressed,
   and until a '.' is typed in the text. */

#include <stdio.h>

int main () {
  int c;
  
  do {
    c = getchar();
    putchar(c);
  } while (c != '.');

  return 0;
}