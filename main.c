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

int aval(int print);
int book();
int check();

//fake booleans
#define true 1
#define false 0

//constants
#define TICKETS 50
int bookings = 0;

int main(void)
{   
    srand(time(NULL));
    printf("Thankyou for showing interest in our Event, you've entered the BOOKING PORTAL.....\n");

    //Selection of function       
    while(1){

        printf("\n-----------------------------------------\n");
        printf("Select what you want to do:\n");
        printf("Enter a to check for availibilty of tickets\n");
        printf("Enter b to book a ticket\n");
        printf("Enter c to check if your ticket is valid\n");
        printf("Enter q to quit\n");
        printf("Input: ");

        char in;
        scanf("%c", &in);

        printf("\n");

        switch (in)
        {
        case 'a':
            aval(true);
            break;
        case 'b':
            book();
            break;
        case 'c':
            check();
            break;
        case 's':
            display_bookings(tickets);
            break;
        case 'q':
            return 0;
        default:
            printf("Invalid option\n");
            break;
        }

        printf("Press any key to continue...\n");
        char temp;
        scanf("%c", &temp);

    }

}

int aval(int print){

    //print only if needed
    if(print){
        printf("%i out of %i tickets are still available\n", TICKETS-bookings, TICKETS);
    }
    
    //check if tickets are left
    return bookings<TICKETS?true:false;

}

//0: booking succesfull
//1: booking unsuccesfull
int book(){

    if(!aval(false)){
        printf("Out of Tickets...\n");
        return 1;
    }

    //create temp vars
    char name_buffer[50];
    holder user;

    //get name of customer
    printf("Name: ");
    scanf("%s", name_buffer);
    name_buffer[strcspn(name_buffer, "\n")] = '\0';  // Remove trailing newline
    user.name = malloc(strlen(name_buffer)+1);
    strcpy(user.name, name_buffer);

    //get reference id
    user.ref_id = generate_id();
    printf("Thank you for your booking. Your ticker reference id is %i\n", user.ref_id);

    //increment no of tickets booked
    bookings++;

    insert(user);

    return 0;

}

//0: found 
//1: checksum invalid 
//2: not found in tree
int check(){

    //get users ref_id
    printf("Enter your ticket reference id: ");
    int id;
    scanf("%d", &id);

    //validate checksum
    if(!checksum(id)){
        printf("This ticket is Invalid...\n");
        return 1;
    }

    //if checksum is valid, only then search the tree for the id
    char* name = search(id);
    if(name){
        //ticket found in tree
        printf("This ticket is booked under the name %s. Enjoy the music festival!\n", name);
        return 0;
    }

    //ticket not found in tree    
    printf("This ticket is Invalid...\n");
    return 2;

}