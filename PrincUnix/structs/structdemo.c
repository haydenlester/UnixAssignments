// Hayden Lester
// CS 3310
// 11/8

#include <stdio.h>

// Struct definition
struct student_info {
	char* student_name;    
	long ssn;	
	char* addr_street;	//"2601 W. Avenue N"
	char* addr_town;	//"San Angelo"
	char  addr_state[2]; //'T' 'X'
	int addr_zip;		// 76909
};


int main() {
   
   //Create a variable of the struct
   struct student_info stuInfo;
   //Init
   stuInfo.addr_street = "2601 W. Avenue N";
   stuInfo.addr_town = "San Angelo";
   stuInfo.addr_state[0] = 'T';
   stuInfo.addr_state[1] = 'X';
   stuInfo.addr_zip = 76909;
   
   printf("Size of stuInfo.student_name: %u\n", sizeof(stuInfo.student_name));
   printf("Size of stuInfo.ssn: %u\n", sizeof(stuInfo.ssn));
   printf("Size of stuInfo.addr_street: %u\n", sizeof(stuInfo.addr_street));
   printf("Size of stuInfo.addr_town: %u\n", sizeof(stuInfo.addr_town));
   printf("Size of stuInfo.addr_state: %u\n", sizeof(stuInfo.addr_state));
   printf("Size of stuInfo.addr_zip: %u\n", sizeof(stuInfo.addr_zip));
   printf("-----------------------------------\n");
   printf("Total size of struct: %u\n", sizeof(stuInfo));
   
}