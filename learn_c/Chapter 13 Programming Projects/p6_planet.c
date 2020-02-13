#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_PLANETS 9
#define MAX_LEN 8

int main(int argc, char* argv[]){

    char *planets[] = {"mercury", "venus", "earth", "mars", "jupiter", "saturn", "uranus", "neptune", "pluto"};
    char planet[MAX_LEN];
    int ch;

    for(int i = 1; i < argc; i++){
        strcpy(planet, argv[i]);
        ch = 0;
        while(planet[ch] != '\0'){
            planet[ch] = tolower(planet[ch]);
            ch++;
        }

        for(int ix = 0; ix < NUM_PLANETS; ix++){
            if(strcmp(planet, planets[ix]) == 0){
                printf("%s is planet %d\n", argv[i], ix+1);
            }
        }
    }



    return 0;
}