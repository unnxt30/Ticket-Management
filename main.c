#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include "libs/structs.h"
#include "libs/bst.h"
#include "libs/display.h"
#include "libs/ids.h"
#include "libs/stacks.h"

// struct x empty = {0};


int main(void)
{   
    srand(time(NULL));

    //Inputing User Info.       
    printf("Thankyou for showing interest in our Event, you've entered the BOOKING PORTAL.....\n");
    
    holder user;
    for(int i = 0; i<res ; i++)
    {   
        char str[20];
        user.ref_id = generate_id();
        printf("NAME: ");
        fgets(user.name, 20, stdin);
        insert(user);
    }

    display_bookings(tickets);

    printf("Plese Enter the ref_id to verify your ticket: ");

    initialize(stack);
    int id;

    scanf("%i", &id);


    while(search(id))
    {
        printf("Your ticket is Valid.\n");
        push(stack, id);

        scanf("%i", &id);
        printf("Plese Enter the ref_id to verify your ticket: ");

    }
    

    printf("ERROR! Ticket not found.\n");
    
    printf("The Number of Entries are %i\n", length_stack(stack));


}