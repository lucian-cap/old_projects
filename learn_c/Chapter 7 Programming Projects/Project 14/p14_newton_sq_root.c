#include <stdio.h>
#include <math.h>

int main(void){

    double user_num, old_guess = 0.00f, new_guess = 1.00f;

    printf("Enter a positive integer: ");
    scanf("%lf", &user_num);

    while((fabs(old_guess-new_guess) > .00001f)){
        old_guess = new_guess;
        new_guess = ((new_guess+(user_num/new_guess))/2.00f);        
    }

    printf("Square root: %f", new_guess);

    return 0;
}