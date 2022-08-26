// Hayden Lester
// Principles of Unix
// 11/1/20

#include "stdio.h"

int main(){
   
   char c;
   char c_array[20];
   char* pc;
   char* pc_array[10];
   
   printf("sizeof int:%lu\n", sizeof(int));
   printf("sizeof long:%lu\n", sizeof(long));
   printf("char c:%lu\n", sizeof(c));
   printf("char c_array[20]:%lu\n", sizeof(c_array));
   printf("char* pc:%lu\n", sizeof(pc));
   printf("char* pc_array[10]:%lu\n", sizeof(pc_array));
   
   return 0;
   
}