#include <stdio.h>
#include <stdlib.h>

#define KEY '&'

int main(int argc, char *argv[]){

    FILE *f_in, *f_out;
    char ch;

    if(argc != 3){
        printf("To use this program, please enter both an input and output file on the command line.\n");
        exit(EXIT_FAILURE);
    }

    if((f_in = fopen(argv[1], "rb")) == NULL){
        printf("File %s could not be opened.\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if((f_in = fopen(argv[2], "rb")) == NULL){
        printf("File %s could not be opened.\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    while((ch = getc(f_in)) != EOF){
        putc(ch ^ KEY, f_out);
    }
    fclose(f_in);
    fclose(f_out);

    printf("Valid termination");



    return 0;
}