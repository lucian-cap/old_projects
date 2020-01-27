#include <stdio.h>

int main(void){

    printf("This program is meant to demonstrate where the various core integer data types fail, based on overflow.\n");

    printf("\nThis set is multiplication demonstrates the limits of a short variable.\n\n");
    for (short i = 1; i < 100000; i+=1000){
        printf("%10d * %10d = %10d\n", i, i, (short)i*(short)i);
        if(i<0){
            break;
        }
    }

    printf("\nThis set is multiplication demonstrates the limits of a int variable.\n\n");
    for (int i = 1; i < 10000000000; i+=100000000){
        printf("%10d * %10d = %10d\n", i, i, (int)i*(int)i);
        if(i<0){
            break;
        }
    }

    printf("\nThis set is multiplication demonstrates the limits of a long variable.\n\n");
    for (long i = 1; i < 10000000000; i+=100000000){
        printf("%10d * %10d = %10d\n", i, i, (long)i*(long)i);
        if(i<0){
            break;
        }
    }


    return 0;
}