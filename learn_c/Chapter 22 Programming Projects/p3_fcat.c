#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    FILE *fp;
    char ch;

    if(argc < 3){
        printf("Please enter at TWO files to use this program.\n");
        exit(EXIT_FAILURE);
    }

    for(int i = 1; i < argc; i++){
        fp = fopen(argv[i], "r");
        if(fp == NULL){
            printf("%s could not be opened. This file was skipped to allow the program to continue.\n", argv[i]);
        } else {
            while((ch = getc(fp)) != EOF){
                putchar(ch);
            }
        }
        fclose(fp);
    }


    return 0;
}