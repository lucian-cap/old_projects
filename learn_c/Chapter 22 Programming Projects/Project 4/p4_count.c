#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    FILE *fp;
    int ch, num_char = 0, num_word = 0, num_line = 0, char_check = 0;

    if (argc != 2){
        printf("To use, please enter a filename on the command line.");
        exit(1);
    }

    if((fp = fopen(argv[1], "r")) == NULL){
        printf("%s could not be opened.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while((ch = getc(fp)) != EOF){
        num_char++;

        if(isalpha(ch)){
            char_check = 1;
        }

        if(isspace(ch) && char_check == 1){
            num_word++;
            char_check = 0;
        }
        if(ch == '\n'){
            num_line++;
        }
        
    }

    fclose(fp);
    num_word++;
    num_line++;

    printf("File %s has %d characters, %d words, and %d lines.\n", argv[1], num_char, num_word, num_line);

    return 0;
}