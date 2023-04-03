void display_bookings(node *tickets)
{   
    if(tickets)
    {
        printf("ID# -> %i, Name -> %s\n", tickets->ticket.ref_id, tickets->ticket.name);
        display_bookings(tickets->left);
        display_bookings(tickets->right);
    }
}
