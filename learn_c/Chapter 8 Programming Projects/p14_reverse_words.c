#include <stdio.h>

int main(void){

    char end, sentence[100];
    int loc = 0, count = 0;

    printf("Enter a sentence: ");

    while((end = getchar()) != '\n'){
        if (end == '.' || end == '!' || end == '?'){
            loc--;
            break;
        } else {
            sentence[loc] = end;
            loc++;
        }
    }

    while(loc >= 0){
        if (sentence[loc] == ' '){
            for(int i = loc+1; i < loc+count+1; i++){
                printf("%c", sentence[i]);
            }
            loc--;
            count = 0;
            printf(" ");
        } else if (loc == 0){
            for (int i = 0; i < count+1; i++){
                printf("%c", sentence[i]);
            }
            break;
        } else{
            loc--;
            count++;
        }
    }
    printf("%c", end);



    return 0;
}