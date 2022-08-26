// Hayden Lester
// CS 3310
// 11/8

#include <stdio.h>

int main(int argc, char *argv[]){
   
   if(argc < 2){
      printf("Please provide me at least one name.\n");
      return -1;
   }
   
   for(int i = 1; i < argc; i++){
      printf("Hello %s, %s says Hi to you!\n", argv[i], argv[0]);
   }
   
   return 0;
}