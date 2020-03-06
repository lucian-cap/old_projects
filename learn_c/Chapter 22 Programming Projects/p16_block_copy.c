#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[]){

    FILE *fp_in, *fp_out;
    char block[BLOCK_SIZE];
    int read_size;

    if(argc != 3){
        printf("Error: Please enter TWO filesnames to use this program.\n");
        exit(EXIT_FAILURE);
    }

    if((fp_in = fopen(argv[1], "rb")) == NULL){
        printf("Error: %s could not be opened.\n", argv[1]);
    }

    if((fp_out = fopen(argv[2], "wb")) == NULL){
        printf("Error: %s could not be opened.\n", argv[2]);
    }

    while((read_size = fread(block, sizeof(char), BLOCK_SIZE, fp_in)) > 0){
        fwrite(block, sizeof(char), read_size, fp_out);
    }

    fclose(fp_in);
    fclose(fp_out);
    
    return 0;
}