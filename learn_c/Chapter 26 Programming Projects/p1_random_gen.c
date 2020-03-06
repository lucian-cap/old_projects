#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){

    srand(time(NULL));

    for(int i = 0; i < 1000; i++){
        printf("%d", rand()%2);
    }

    return 0;
}