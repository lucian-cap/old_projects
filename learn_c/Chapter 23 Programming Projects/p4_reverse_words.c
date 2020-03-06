#include <stdio.h>
#include <string.h>

#define MAX_LEN 200

int main(void){
    char sentence[MAX_LEN], *words[MAX_LEN];
    int i = 0;

    printf("Enter a series of words separated by a single space: ");
    fgets(sentence, MAX_LEN, stdin);
    sentence[strlen(sentence)-1] = '\0';

    if((words[i] = strtok(sentence, " ")) == NULL){
        return 0;
    }

    i++;
    while((words[i] = strtok(NULL, " ")) != NULL){
        i++;
    }

    for(i--; i >= 0; i--){
        printf("%s ", words[i]);
    }
    printf("\n");


    return 0;
}