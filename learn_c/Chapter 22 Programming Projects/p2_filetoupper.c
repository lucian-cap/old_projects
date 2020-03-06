#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    FILE *fp;
    char ch;

    if(argc != 2){
        printf("To use this program, please enter a filename.\n");
        exit(EXIT_FAILURE);
    }

    if((fp = fopen(argv[1], "r")) == NULL){
        printf("%s could NOT be opened. Please check the files presence in the local directory.\n");
        exit(EXIT_FAILURE);
    }

    while((ch = getc(fp)) != EOF){
        if(isalpha(ch)){
            putchar(toupper(ch));
        } else {
            putchar(ch);
        }
    }
    flcose(fp);

    return 0;
}