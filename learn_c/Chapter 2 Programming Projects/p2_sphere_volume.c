#include <stdio.h>

#define PI (3.1415)
#define SPHERE_COEFFICIENT ((4.0f/3.0f)*PI)

int main(void){

    int radius = 10;
    float volume = radius * radius * radius * SPHERE_COEFFICIENT;

    printf("Volume of a sphere with radius %d is %.2f\n", radius, volume);

    return 0;   
    
}