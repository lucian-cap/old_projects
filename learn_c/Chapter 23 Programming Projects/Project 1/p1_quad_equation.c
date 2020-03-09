#include <stdio.h>
#include <math.h>

int main(void){

    int a, b, c, num;
    float det;

    printf("Enter the values for a, b, and c (in this order): ");

    while(num = scanf(" %d %d %d", &a, &b, &c) != 3){
        printf("There was an error while reading your input. Please try again.\n");
        printf("Enter the values for a, b, and c (in this order): ");
    }
    det = pow(b, 2) - (4 * a *c);

    if(det < 0){
        printf("This function has complex solutions that this program is not designed to handle.\n");
        return 0;
    } else {
        printf("The solutions to the equation %dx^2 + %db + %d = 0 are: %f and %f\n", a, b, c,((-1 * b) + sqrt(det)) / (float)(2*a), ((-1 * b) - sqrt(det)) / (float)(2*a));
    }

    return 0;
}