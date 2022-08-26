/* fileop.c     */
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{
	FILE *Ifp, *Ofp;
	int num;
        char First[100], Last[100], Middle[3];

	// open output file
	Ifp = fopen(argv[1],"r");
	if ( Ifp == NULL ) {
        fprintf(stderr, "Can't open input file: %s\n", argv[1] ) ;
        exit(1) ;
    }
	Ofp = fopen(argv[2],"w");
	if ( Ofp == NULL ) {
        fprintf(stderr, "Can't open output file: %s\n", argv[2] ) ;
        exit(1) ;
    }

        fscanf(Ifp,"%s %s %s",First, Last, Middle);
        fprintf(Ofp,"First Name: %s Last Name: %s %s\n",First, Last, Middle);

         fclose(Ifp);fclose(Ofp);

           return 0;
}
