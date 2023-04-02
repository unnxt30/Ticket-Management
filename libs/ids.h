// Limiting the event to a 100 Tickets only.

int toNum(char c)
{
    int i = c -'0' ;
    return i;
}

//Generates a unique ref_id for each ticket.
int generate_id()
{

    // srand(time(NULL)); // seed the random number generator with the current time
    
    int num = rand() % (999 - 100 + 1) + 100; // generate first three digit of ID
    
    char str[3];
    int twoSum = 0;

    sprintf(str, "%i", num); //convert number to string

    for(int i = 0; i<3; i++)
    {
        twoSum += toNum(str[i]);
    }

    num = (num*100) + twoSum;

    return num;

}
