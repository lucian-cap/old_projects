#include <stdio.h>
#include <string.h>

#define SIZE 20

int main(void){

    char smallest_word[SIZE], largest_word[SIZE], current[SIZE];

    printf("Enter word: ");
    gets(current);
    strcpy(smallest_word, strcpy(largest_word, current));

    while(1){
        printf("Enter word: ");
        gets(current);

        if(strcmp(smallest_word, current) > 0){
            strcpy(smallest_word, current);
        } else if (strcmp(largest_word, current) < 0){
            strcpy(largest_word, current);
        }

        if (strlen(current) == 4){
            break;
        }
    }

    printf("Smallest word: %s\n", smallest_word);
    printf("Largest word: %s", largest_word);

    return 0;
}