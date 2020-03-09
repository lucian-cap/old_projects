#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 100

double compute_average_word_length(const char *sentence);

int main(void){

    char sen[MAX_LEN+1];

    printf("Enter sentence: ");
    fgets(sen, MAX_LEN, stdin);

    printf("Average word length is: %.2f", compute_average_word_length(sen));
    return 0;
}

double compute_average_word_length(const char *sentence){
    int len = 0, num_word = 0;

    while(*sentence != '\0'){
        if(*sentence == ' '){
            num_word++;
        } else if(isalpha(*sentence)){
            len++;
        }
        sentence++;
    }
    num_word++;

    return ((double)len/(double)num_word);
}