#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    FILE *fp;

    if (argc < 2){
        printf("To use, please enter at least one filename.");
        exit(1);
    }

    for(int i = 1; i < argc; i++){
        fp = fopen(argv[i], "r");

        if(fp == NULL){
            printf("Cannot open file: %s\n", argv[i]);
            fclose(fp);
            exit(EXIT_FAILURE);
        } else {
            printf("%s can be opened.\n", argv[i]);
        }
        fclose(fp);
    }

    return 0;
}