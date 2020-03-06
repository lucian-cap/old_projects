#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

    FILE *fp_in, *fp_out;
    unsigned char ch_cur, ch_next;
    char out_file[strlen(argv[1]+5)];
    int count = 1;

    if(argc != 2){
        printf("Enter a filename on the command line to use this program.\n");
        exit(EXIT_FAILURE);
    }

    if((fp_in = fopen(argv[1], "rb")) == NULL){
        printf("Error: %s could not be opened.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    strcpy(out_file, argv[1]);
    strcat(out_file, ".rle");
    if((fp_out = fopen(out_file, "wb")) == NULL){
        printf("Error: %s could not be used as the output file.\n", out_file);
        fclose(fp_in);
        exit(EXIT_FAILURE);
    }

    fread(&ch_cur, sizeof(unsigned char), 1, fp_in);
    fread(&ch_next, sizeof(unsigned char), 1, fp_in);

    while(1){
        if(ch_cur == ch_next){
            count++;
        } else{
            fwrite(&count, sizeof(int), 1, fp_out);
            fwrite(&ch_cur, sizeof(unsigned char), 1, fp_out);
            count = 1;
            ch_cur = ch_next;
        }
        fread(&ch_next, sizeof(unsigned char), 1, fp_in);
        if(feof(fp_in)){
            break;
        }
    }
    fwrite(&count, sizeof(int), 1, fp_out);
    fwrite(&ch_cur, sizeof(unsigned char), 1, fp_out);

    fclose(fp_in);
    fclose(fp_out);

    return 0;
}