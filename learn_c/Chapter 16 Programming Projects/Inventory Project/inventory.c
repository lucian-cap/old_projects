#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "readline.h"

#define MAX_PARTS 100
#define MAX_NAME 30

struct part {
    int number;
    char name[MAX_NAME+1];
    int quantity;
    float price;
};

int find_part(struct part *inven, const int num_part, const int search_num);
void insert(struct part *inven, int *num_part);
void search(struct part *inven, int num_part);
void update(struct part *inven, int num_part);
void change(struct part *inven, int num_part);
void print(struct part *inven, int num_part);
void update_inventory(struct part *inven, int left, int right);

int main(void){

    char user_command;
    struct part inventory[MAX_PARTS];
    int num_parts = 0;

    while(1){
        printf("\n\nOperation Codes: Insert: 'i', Search 's', Update Quantity: 'u', Change Price: 'c', Print: 'p', Quit: 'q'\nEnter operation code: ");
        scanf(" %c", &user_command);
        while((getchar() != '\n'));

        switch (tolower(user_command)){
        case 'i':
            insert(inventory, &num_parts);
            break;
        case 's':
            search(inventory, num_parts);
            break;
        case 'u':
            update(inventory, num_parts);
            break;
        case 'c':
            change(inventory, num_parts);
            break;
        case 'p':
            print(inventory, num_parts);
            break;
        case 'q':
            exit(0);
            break;
        default:
            printf("That command was not recognized.\n");
            break;
        }
    }

    return 0;
}

int find_part(struct part *inven, const int num_part, const int search_num){
    int r_val = -1;

    for(int i = 0; i < num_part; i++){
        if(inven->number == search_num){
            r_val = i;
            break;
        }
        inven++;
    }
    return r_val;
}

void insert(struct part *inven, int *num_part){
    struct part new_part;
    struct part *og_inven = inven;

    if(*num_part == MAX_PARTS){
        printf("ERROR: Inventory is at maximum. Cannot create any new parts.\n");
    } else {
        printf("Enter new part number: ");
        scanf(" %d", &new_part.number);

        if(find_part(inven, *num_part, new_part.number) != -1){
            printf("ERROR: A part with that number already exists.\n");
        } else {
            printf("Enter new part name: ");
            read_line(new_part.name, MAX_NAME+1);

            printf("Enter new part quantity: ");
            scanf(" %d", &new_part.quantity);

            printf("Enter new part price: ");
            scanf(" %f", &new_part.price);

            if(*num_part == 0){
                *inven = new_part;
            } else {
                inven += *num_part;
                *inven = new_part;
            }
            
            (*num_part)++;
            update_inventory(og_inven, 0, (*num_part)-1);
        }
    }
}

void search(struct part *inven, int num_part){
    int user_num, position;

    printf("Enter the part number to search for: ");
    scanf(" %d", &user_num);

    position = find_part(inven, num_part, user_num);

    if(position == -1){
        printf("ERROR: No part with that number was found.\n");
    } else {
        inven += position;
        printf("Part Name: %s\nQuantity on hand: %d\nPrice of part: %.2f\n", inven->name, inven->quantity, inven->price);
    }
}

void update(struct part *inven, int num_part){
    int user_num, position;

    printf("Enter part number: ");
    scanf(" %d", &user_num);

    position = find_part(inven, num_part, user_num);

    if(position == -1){
        printf("ERROR: No part with that number was found.\n");
    } else {
        inven += position;

        printf("Current Quantity: %d\n", inven->quantity);

        printf("Enter change in quantity: ");
        scanf(" %d", &user_num);

        inven->quantity += user_num;
    }
}

void change(struct part *inven, int num_part){
    int user_num, position;

    printf("Enter part number: ");
    scanf(" %d", &user_num);

    position = find_part(inven, num_part, user_num);

    if(position == -1){
        printf("ERROR: No part with that number was found.\n");
    } else {
        inven += position;

        printf("Current Price: %.2f\n", inven->price);

        printf("Enter change in price: ");
        scanf(" %d", &user_num);

        inven->price += user_num;
    }
}

void print(struct part *inven, int num_part){

    printf("Part Number\tPart Name\t\t\tQuantity\tPrice\n");
    for(int i = 0; i < num_part; i++){
        printf("%-12d\t%-30s\t%-12d\t%.2f\n", inven->number, inven->name, inven->quantity, inven->price);
        inven++;
    }
}

void update_inventory(struct part *inven, int left, int right){
    int og_left = left, og_right = right;
    struct part temp;
    
    if(left < right){
        struct part pivot = *(inven+right);
        right--;

        while(1){
            while((inven+left)->number<pivot.number){
                left++;
            }
            while((inven+right)->number>=pivot.number && right >= left){
                right--;
            }
            if(left < right){
                temp = *(inven+left);
                *(inven+left) = *(inven+right);
                *(inven+right) = temp;
            }
            if(left > right){
                break;
            }
        }
        *(inven+og_right) = *(inven+left);
        *(inven+left) = pivot;
    
        update_inventory(inven, og_left, left-1);
        update_inventory(inven, left+1, og_right);
    }

}