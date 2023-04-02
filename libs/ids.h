#include "bst.h"

// Limiting the event to a 100 Tickets only.
#define EVENT_SIZE 100

int ids[EVENT_SIZE];

//checks if the id is present in the Booked tickets.
int is_id(int ref_id, int ids[])
{
    for (int i = 0; i<EVENT_SIZE; i++)
    {
        if(ref_id == ids[i])
        {
            return 1;
        }
    }

    return 0;
}

//Generates a unique ref_id for each ticket.
void *generate_id(int ids[])
{

    srand(time(NULL)); // seed the random number generator with the current time
    
    // create an array to hold the n random numbers
    ids[0] = rand() % (100 - 0 + 1) + 0; // generate the first random number
    
    for (int i = 1; i < EVENT_SIZE; i++) {
        ids[i] = ids[i-1]; // initialize the next number to the previous number
        while (ids[i] == ids[i-1]) { // loop until the next number is different from the previous number
            ids[i] = rand() % (100 - 0 + 1) + 0; // generate a new random number
        }
    }

}
