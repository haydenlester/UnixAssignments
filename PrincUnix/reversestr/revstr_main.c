// Hayden Lester
// CS3310
// 11/8
#include "revstr.h"
#include <stdio.h>
#include <string.h>

int main() {
   
   char str[80]; // The string
   char *endChar; // The ending character (ptr)
   int strLen; // String Length
   char playAgain = 'y';
   
   while(playAgain != 'n'){
      printf("Hey there... give me a string: ");
      
      // take input and find end of string as ptr
      scanf("%s", str);
      for(endChar = str; *endChar != '\0'; endChar++){
         strLen++;
      }
      
      reverseString(str, endChar, strLen);
      
      printf("And the reversed string is: %s\n", str);
      printf("Would you like to play again? (y or n): ");
      scanf("%c", playAgain);
   }
   return 0;
}