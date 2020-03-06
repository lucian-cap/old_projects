#include <stdio.h>
#include <math.h>

int main(void){
    double real, image, r, theta;

    printf("Enter real value of complex number: ");
    scanf("%lf", &real);
    printf("Enter imaginary value of complex number: ");
    scanf("%lf", &image);

    r = sqrt(real*real + image*image);
    theta = atan(real / image);

    printf("%lf %c %lf in polar coordinates is: r = %g, theta = %g radians\n", real, image>0?'+':'-', image, r, theta);

    return 0;
}