//Basic Structure of the data of the ticket holders.
typedef struct
{
    char *name;
    int ref_id;
}
holder;

holder *holders[EVENT_SIZE];