//Basic Structure of the data of the ticket holders.
typedef struct Holder
{
    char *name;
    int ref_id;
    int entered;
}
holder; 

//Nodes of our BST
typedef struct Node{
    
    holder ticket;
    struct Node* left;
    struct Node* right;

} node;
