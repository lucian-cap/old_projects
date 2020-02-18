#include <stdio.h>

int search_country(const int user_code);

struct dialing_code {
    char *country;
    int code;
};

int num_country = 32;

const struct dialing_code country_codes[] = 
    {{"Argentina", 54}, {"Bangladesh", 880},
     {"Brazil", 55}, {"Burma (Myanmar", 95},
     {"China", 86}, {"Colombia", 57},
     {"Congo, Dem. Rep. of", 243}, {"Egypt", 20},
     {"Ethiopia", 251}, {"France", 33},
     {"Germany", 49}, {"India", 91},
     {"Indonesia", 62}, {"Iran", 98},
     {"Italy", 39}, {"Japan", 81},
     {"Mexico", 52}, {"Nigeria", 234},
     {"Pakistan", 92}, {"Philippines", 63},
     {"Poland", 48}, {"Russia", 7},
     {"South Africa", 27}, {"South Korea", 82},
     {"Spain", 34}, {"Sudan", 249},
     {"Thailand", 66}, {"Turkey", 90},
     {"Ukraine", 380}, {"United Kingdom", 44},
     {"United States", 1}, {"Vietnam", 84}};

int main(void){

    int user_code, position;

    printf("Please enter the country code to search for: ");
    scanf(" %d", &user_code);
    
    position = search_country(user_code);

    if(position != -1){
        printf("The code %d belongs to country %s.", user_code, country_codes[position].country);
    } else {
        printf("The code you entered does not belong to a country in our listing.");
    } 

    return 0;
}

int search_country(const int user_code){
    int r_val = -1;

    for(int i = 0; i < num_country; i++){
        if(country_codes[i].code == user_code){
            r_val = i;
            break;
        }
    }

    return r_val;
}