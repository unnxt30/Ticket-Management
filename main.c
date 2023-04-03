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
    
    // holder user;
    // for(int i = 0; i<res ; i++)
    // {   
    //     char str[20];
    //     user.ref_id = generate_id();
    //     printf("NAME: ");
    //     fgets(user.name, 20, stdin);
    //     insert(user);
    // }
    holder *users = malloc(sizeof(holder) * res);

    for (int i = 0; i < res; i++) 
    {   
        /*You're correct, the issue is that the name field of each User struct is being overwritten with each iteration of the loop, so 
        that all instances end up with the same name as the last one entered. To fix this, you need to allocate a separate buffer 
        for each name and copy the input into it.*/

        /*In this version, we first allocate a temporary buffer name_buffer to read each name input. We then allocate a separate buffer 
        for the name field of each User struct using malloc, and copy the input into it using strcpy. This ensures that each User has its
        own buffer for its name field*/
        char name_buffer[20];
        holder user;
        printf("Name: ");
        fgets(name_buffer, 50, stdin);
        name_buffer[strcspn(name_buffer, "\n")] = '\0';  // Remove trailing newline
        user.name = malloc(strlen(name_buffer)+1);
        strcpy(user.name, name_buffer);
        user.ref_id = generate_id();

        users[i] = user;

    }

//     for (int i = 0; i < res; i++) {
//     printf("User %d: name=%s, id=%d\n", i+1, users[i].name, users[i].ref_id);
// }

    for (int i = 0; i<res; i++)
    {
        insert(users[i]);
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