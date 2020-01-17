#include <stdio.h>

#define PI 3.1415
#define SPHERE_COEFFICIENT ((4.0f / 3.0f) * PI)

int main(void){

    float radius;

    printf("Please enter the radius of the sphere you would like the volume of: ");
    scanf("%f", &radius);

    printf("The volume of a sphere with radius %.2f is %.2f\n", radius, radius*radius*radius*SPHERE_COEFFICIENT);

    return 0;
}