#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

    FILE *fp_in, *fp_out;
    char *end = malloc(sizeof(char)*5), *output_name = malloc(sizeof(char)*(strlen(argv[1]))-4);
    unsigned char ch;
    int num;

    if(argc != 2){
        printf("Enter a file name to decompress.\n");
        free(end);
        free(output_name);
        exit(EXIT_FAILURE);
    }

    end = &argv[1][strlen(argv[1])-4];
    if(strcmp(end, ".rle") != 0){
        printf("File %s entered was not created by the compresser program.\n", argv[1]);
        free(end);
        free(output_name);
        exit(EXIT_FAILURE);
    }

    if((fp_in = fopen(argv[1], "rb")) == NULL){
        printf("Error while opening %s", argv[1]);
        free(end);
        free(output_name);
        exit(EXIT_FAILURE);
    }

    if((fp_out = fopen(output_name, "wb")) == NULL){
        printf("Error while opening %s", output_name);
        free(end);
        free(output_name);
        exit(EXIT_FAILURE);
    }

    while(1){
        fread(&num, sizeof(int), 1, fp_in);
        fread(&ch, sizeof(unsigned char), 1, fp_in);

        for(int i = 0; i < num; i++){
            putc(ch, fp_out);
        }

        if(feof(fp_in)){
            break;
        }
    }
    


    return 0;
}