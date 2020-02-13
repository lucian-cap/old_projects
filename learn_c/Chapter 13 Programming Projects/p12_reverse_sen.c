#include <stdio.h>

#define MAX_WORD 30
#define MAX_LEN 20

int read_sentence(char words[MAX_WORD][MAX_LEN+1], char *sen, char *end);


int main(void){

    char sen[MAX_WORD][MAX_LEN+1], sentence[MAX_WORD*MAX_LEN+1], end;

    printf("Enter a sentence: ");
    fgets(sentence, MAX_WORD*MAX_LEN, stdin);

    for(int i = read_sentence(sen, sentence, &end); i >= 0; i--){
        printf("%s", sen[i]);
        if(i > 0){
            printf(" ");
        }
    }
    printf("%c", end);

    return 0;
}

int read_sentence(char words[MAX_WORD][MAX_LEN+1], char *sen, char *end){
    int word = 0, ch = 0;

    while(*sen != '\0' && *sen != '\n'){
        if(*sen == ' '){
            words[word][ch] = '\0';
            word++;
            ch = 0;
        } else if (*sen == '?' || *sen == '!' || *sen == '.'){
            *end = *sen;
        } else if (ch < MAX_LEN){
            words[word][ch] = *sen;
            ch++;
        } else if (ch >= MAX_LEN){
            words[word][MAX_LEN] = '\0';
        }
        sen++;
    }
    return word;

}