#include <stdio.h>
#include <ctype.h>

#define SIZE 15

int main(void){

    char number[SIZE];
    int loc = 0;

    printf("Enter phone number: ");

    while((number[loc] = getchar()) != '\n'){
        loc++;
    }

    printf("In numeric form: ");
    for (int i = 0; i <= loc; i++){
        switch(toupper(number[i])){
            case 'A': case 'B': case 'C': printf("%d", 2); break;
            case 'D': case 'E': case 'F': printf("%d", 3); break;
            case 'G': case 'H': case 'I': printf("%d", 4); break;
            case 'J': case 'K': case 'L': printf("%d", 5); break;
            case 'M': case 'N': case 'O': printf("%d", 6); break;
            case 'P': case 'R': case 'S': printf("%d", 7); break;
            case 'T': case 'U': case 'V': printf("%d", 8); break;
            case 'W': case 'X': case 'Y': printf("%d", 9); break;
            default: printf("%c", number[i]); break;
        }
    }




    return 0;
}