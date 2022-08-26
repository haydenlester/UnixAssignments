/* Hayden Lester  */
/* array and pointer Example, modified for HW submission. file from Dr. Lopa */
/* pointer_prog.c */

#include <string.h>
#include <limits.h>
#include <stdio.h>


int main()
{
   int integers[26];
   // For loop initialization is far easier to code in
   // though likely slightly less efficient
   // in this case (and most cases) it won't matter much.
   for(int i = 0; i < 26; i++){integers[i] = 65+i;};
   
   int* p = integers;
   int ch;
   
   // Calculate size and length
   int len = sizeof(integers) / sizeof(int);
   int sz = sizeof(integers);
   
   // Print size and length
   printf("Size of integer array is %d, length of integer array is %d\n", sz, len);
   
   // Could make p intrinsically part of this for loop
   // Just leave init blank, right-bound p by integers+len and postincr p. and then we don't have a "wasted" increment operation
   for(int i = 0; i < len; i++){
      ch = *p;
      printf("%c %d %o %x\n", ch, ch, ch, ch);
      p++;
   }
   
   printf("out of loop: last character is %c %o %x\n", ch,ch,ch);
}
