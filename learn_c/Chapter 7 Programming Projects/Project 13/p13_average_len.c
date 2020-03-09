#include <stdio.h>

int main(void){

    int len = 0, num_words = 0;
    char ch;
    float average = 0.00f;

    printf("Enter a sentence: ");

    while ((ch = getchar()) != '\n'){
        if(ch == ' '){
            average += len;
            num_words++;
            len = 0;
        } else {
            len++;
        }
    }
    average += len;
    num_words++;
    average /= num_words;

    printf("Average word length: %.1f\n", average);


    return 0;
}