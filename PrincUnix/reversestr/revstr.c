// Hayden Lester
// CS3310
// 11/8

#include "stdio.h"

void reverseString(char* startStr, char* finStr, int strLength){
   
   char temp;
   
   *(finStr+1) = '\0';
   
   for(finStr--; startStr < finStr; startStr++, finStr--){
      temp = *startStr;
      *startStr = *finStr;
      *finStr = temp;
   }
}