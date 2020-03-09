#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void *n1, const void *n2);

int main(void){

    int array[100000], i = 100000;
    clock_t start;
    clock_t end;

    for(int j = 0; j < 100000; j++){
        array[j] = i;
        i--;
    }

    start = clock();
    qsort(array, 1000, sizeof(int), compare);
    end = clock();
    printf("It took %g seconds to sort 1000 values.\n", end - start / (double) CLOCKS_PER_SEC);

    i = 100000;
    for(int j = 0; j < 1000; j++){
        array[j] = i;
        i--;
    }

    start = clock();
    qsort(array, 10000, sizeof(int), compare);
    end = clock();
    printf("It took %g seconds to sort 10000 values.\n", end - start / (double) CLOCKS_PER_SEC);

    i = 100000;
    for(int j = 0; j < 10000; j++){
        array[j] = i;
        i--;
    }

    start = clock();
    qsort(array, 100000, sizeof(int), compare);
    end = clock();
    printf("It took %g seconds to sort 100000 values.\n", end - start / (double) CLOCKS_PER_SEC);

    return 0;
}

int compare(const void *n1, const void *n2){
    return *((int *)n1)-*((int *)n2);
}