#define res 3 

void display_bookings(holder *holders[])
{   
    printf("\n");
    for(int i = 0; i<res ; i++)
    {
        printf("ID# -> %i, NAME -> %s", holders[i] -> ref_id, holders[i] -> name);
        printf("\n");
    }
}

void display_ids(int ids[])
{
    for(int i = 0; i<res; i++)
    {
        printf("%i\n", ids[i]);
    }
}