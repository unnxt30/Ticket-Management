#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "libs/ids.h"
#include "libs/structs.h"
// #include "bookings.h"
#include "libs/display.h"


void display_bookings(holder *holders[]);

holder book_ticket(holder *holders[], int ids[] );


int main(void)
{   
    srand(time(NULL));
    generate_id(ids);


    //Inputing User Info.       
    printf("Thankyou for showing interest in our Event, you've entered the BOOKING PORTAL.....\n");

    for(int i = 0; i<res ; i++)
    {
        holder *data = malloc(sizeof(holder));
        char str[20];
        printf("NAME: ");
        fgets(str, 20, stdin);
        data -> name = str;
        data -> ref_id = ids[i];
        holders[i] = data;
    }

    display_bookings(holders);


}