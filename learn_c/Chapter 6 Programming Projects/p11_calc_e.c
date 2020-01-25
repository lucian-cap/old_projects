#include <stdio.h>

int main(void){

    float e = 1.00f;
    int user_num, denom;

    printf("Enter the integer to use while calculating 'e': ");
    scanf("%d", &user_num);

    for (int i = 1; i <= user_num; i++){
        denom = 1.00f;
        for (int ix = i; ix >= 2; ix--){
            denom *= ix;
        }
        e += 1.00f/denom;
    }

    printf("e calculated using %d is: %f", user_num, e);



    return 0;
}