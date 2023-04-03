node* tickets = NULL;

int insert(holder x){
    
    node* current = tickets;

    while(current != NULL)
    {
        if(x.ref_id < current->ticket.ref_id)
        {

            if(current->left == NULL){
                current->left = malloc(sizeof(node));
                current = current->left;
                current->ticket.name = x.name;
                current->ticket.ref_id = x.ref_id;
                current->left = NULL;
                current->right = NULL;

                return 0;
            }
            current = current->left;

        }
        else if(x.ref_id > current->ticket.ref_id){

            if(current->right == NULL){
                current->right = malloc(sizeof(node));
                current = current->right;
                current->ticket.name = x.name;
                current->ticket.ref_id = x.ref_id;
                current->left = NULL;
                current->right = NULL;

                return 0;
            }
            current = current->right;
            
        }else{
            //same ref_id has been generated twice
            return 1;
        }
    }

    current = malloc(sizeof(node));
    current->ticket.name = x.name;
    current->ticket.ref_id = x.ref_id;
    current->left = NULL;
    current->right = NULL;

    tickets = current;

    return 0;

}

char* search(int ref_id){

    node* current = tickets;

    while(current!=NULL){
        if(ref_id < current->ticket.ref_id){

            if(current->left == NULL){
                
                //reached a leaf node without finding ticket
                return NULL;
            }
            current = current->left;

        }else if(ref_id > current->ticket.ref_id){

            if(current->right == NULL){

                //reached a leaf node without finding ticket
                return NULL;
            
            }
            current = current->right;
            
        }else{
            //found
            return current->ticket.name;
        }
    }  

}

// holder initialize()
// {
//     node* current = tickets;

//     while(current!=NULL){
//         if(ref_id < current->ticket.ref_id){

//             if(current->left == NULL){
                
//                 //reached a leaf node without finding ticket
//                 return;
//             }
//             current = current->left;

//         }else if(ref_id > current->ticket.ref_id){

//             if(current->right == NULL){

//                 //reached a leaf node without finding ticket
//                 return;
            
//             }
//             current = current->right;
            
//         }else{
//             //found
//             return current -> ticket;
//         }
//     }    
// }