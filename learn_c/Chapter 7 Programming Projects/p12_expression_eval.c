#include <stdio.h>

/*Evaluates expression left to right, ignoring operator precedence*/

int main(void){

    float val, total = 0.00f;
    char op;

    printf("Enter an expression: ");
    scanf("%f", &total);

    while ((op = getchar()) != '\n'){
        scanf("%f", &val);
        switch(op){
            case '+': 
                total+= val;
                break;
            case '-': 
                total -= val;
                break;
            case '*': 
                total *= val;
                break;
            case '/': 
                total /= val;
                break;
        }
    }

    printf("Value of expression: %f", total);

    return 0;
}