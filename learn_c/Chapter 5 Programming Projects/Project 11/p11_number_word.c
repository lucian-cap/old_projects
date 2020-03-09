#include <stdio.h>

int main(void){

    int tens, ones;
    
    printf("Enter a two-digit number: ");
    scanf("%1d%1d", &tens, &ones);

    printf("You entered the number ");

    switch (tens){
        case 1: 
            switch (ones){
                case 0: printf("ten.\n"); break;
                case 1: printf("eleven.\n"); break;
                case 2: printf("twelve.\n"); break;
                case 3: printf("thir"); break;
                case 4: printf("four"); break;
                case 5: printf("fif"); break;
                case 6: printf("six"); break;
                case 7: printf("seven"); break;
                case 8: printf("eigh"); break;
                case 9: printf("nin"); break;
            }
            if (ones != 0 && ones != 1 && ones != 2){
                printf("teen.\n");
            }
            break;
        case 2: printf("twenty"); break;
        case 3: printf("thirty"); break;
        case 4: printf("forty"); break;
        case 5: printf("fifty"); break;
        case 6: printf("sixty"); break;
        case 7: printf("seventy"); break;
        case 8: printf("eighty"); break;
        case 9: printf("ninety"); break;
    }
    if (tens != 1){
        switch (ones){
            case 0: printf(".\n"); break;
            case 1: printf("-one.\n"); break;
            case 2: printf("-two.\n"); break;
            case 3: printf("-three.\n"); break;
            case 4: printf("-four.\n"); break;
            case 5: printf("-five.\n"); break;
            case 6: printf("-six.\n"); break;
            case 7: printf("-seven.\n"); break;
            case 8: printf("-eight.\n"); break;
            case 9: printf("-nine.\n"); break;
        }
    }


    return 0;
}