#include <stdio.h>
#include <ctype.h>

int main(void){

    char message[100], ch;
    int chars = 0;

    printf("Enter message: ");

    while ((ch = getchar()) != '\n'){
        message[chars] = ch;
        chars++;
    }

    printf("In B1FF-speak: ");
    for(int i = 0; i < chars; i++){
        switch(toupper(message[i])){
            case 'A': printf("4"); break;
            case 'B': printf("8"); break;
            case 'E': printf("3"); break;
            case 'I': printf("1"); break;
            case 'O': printf("0"); break;
            case 'S': printf("5"); break;
            default: printf("%c", message[i]); break;
        }
    }

    return 0;
}