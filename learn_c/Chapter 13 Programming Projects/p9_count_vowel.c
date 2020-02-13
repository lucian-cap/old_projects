#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

int compute_vowel_count(const char *sentence);

int main(void){

    char sen[MAX_LEN+1];

    printf("Enter sentence to count the vowels: ");
    gets(sen);

    printf("Your sentence has %d vowels.", compute_vowel_count(sen));

    return 0;

}

int compute_vowel_count(const char *sentence){
    int count = 0;
    char ch;

    while(*sentence != '\0'){
        ch = *sentence;
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            count++;
        }
        sentence++;
    }
    return count;
}