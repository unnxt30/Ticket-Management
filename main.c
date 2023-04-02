#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "libs/ids.h"
#include "libs/structs.h"
#include "libs/bst.h"
// #include "bookings.h"
#include "libs/display.h"


void display_bookings(holder *holders[]);

holder book_ticket(holder *holders[], int ids[] );


int main(void)
{
    generate_id(ids);


    //Inputing User Info.       
    printf("Thankyou for showing interest in our Event, you've entered the BOOKING PORTAL.....\n");

    for(int i = 0; i<res ; i++)
    {
        char str[20];
        printf("NAME: ");
        fgets(str, 20, stdin);
        holder temp;
        temp.name = str;
        temp.ref_id = generate_id;
        insert(temp);
    }

    display_bookings(holders);


}