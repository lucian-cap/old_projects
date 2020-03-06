#include <stdio.h>
#include <complex.h>
#include <math.h>

int main(void){

    double a, b, c;

    printf("Enter a, b, and c (in this order): ");
    scanf("%lf%lf%lf", &a, &b, &c);
    
    double complex discriminant_sqrt = csqrt(b * b - 4 * a * c);
    double complex root1 = (-b + discriminant_sqrt) / (2 * a);
    double complex root2 = (-b - discriminant_sqrt) / (2 * a);

    if(cimag(discriminant_sqrt) == 0){
        printf("root1 = %g\n", creal(root1));
        printf("root2 = %g\n", creal(root2));

    } else {
        printf("root1 = %g %c %gi\n", creal(root1), cimag(root1) > 0? '+':'-', fabs(cimag(root1)));
        printf("root2 = %g %c %gi\n", creal(root2), cimag(root2) > 0? '+':'-', fabs(cimag(root2)));
    }

    return 0;
}