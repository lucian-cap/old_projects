#include <stdio.h>

int main(void){

    int f1_num, f1_den, f2_num, f2_den, f3_num, f3_den;
    char op;

    printf("Enter two fractions separated by the sign of your operation: ");
    scanf("%d/%d%c%d/%d", &f1_num, &f1_den, &op, &f2_num, &f2_den);
    getchar();

    while (op != '+' && op != '-' && op != '*' && op != '/'){
        printf("The operation entered was not recognized, please enter one of the following (+, -, *, /): ");
        op = getchar();
    }

    printf("The ");
    switch(op){
        case '+':
            f3_num = f1_num*f2_den + f1_den*f2_num;
            f3_den = f1_den * f2_den;
            printf("sum ");
            break;
        case '-': 
            f3_num = f1_num*f2_den - f1_den*f2_num;
            f3_den = f1_den * f2_den;
            printf(" difference ");
            break;
        case '*': 
            f3_num = f1_num * f2_num;
            f3_den = f1_den * f2_den;
            printf(" product ");
            break;
        case '/': 
            f3_num = f1_num * f2_den;
            f3_den = f1_den * f2_num;
            printf(" quotient ");
            break;
    }

    printf(" is %d/%d", f3_num, f3_den);
    
    return 0;
}