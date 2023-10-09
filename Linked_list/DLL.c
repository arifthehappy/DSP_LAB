#include <stdio.h>
#include <stdlib.h>

struct dllNode{
    struct dllNode *left;
    int data;
    struct dllNode *right;
}dllNode;

struct dllNode *head = NULL;

// display double linked list
void display(){
    struct dllNode *temp;
    temp = head;
    if(head == NULL){
        printf("LIST is EMPTY\n\n");
        return;
    }
    printf("\nList is: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->right;
    }
    printf("\n\n");
}

// create a node
struct dllNode *create_node(int val){
    struct dllNode *new_node;
    new_node = (struct dllNode *) malloc(sizeof(struct dllNode));
    new_node->data = val;
    new_node->right = NULL;
    new_node->left = NULL;
    return new_node;
}

// count number of nodes
int count_node(struct dllNode *head){
    int count = 0;
    struct dllNode *temp;
    temp = head;
    while(temp != NULL){
        count++;
        temp = temp->right;
    }
    return count;
}

// Insert a node at the begining of DLL
void insert_beg(int val){
    struct dllNode * new_node;
    new_node = create_node(val);
    if(head == NULL){
        head = new_node;
    }
    else{
        new_node -> right = head;
        head->left =  new_node;
        head = new_node;
    }
}

// Insert a node at end of DLL
void insert_end(int val){
    struct dllNode * new_node;
    new_node = create_node(val);
    if(head == NULL){
        head = new_node;
    }
    else {
        struct dllNode * temp;
        temp = head;
        while(temp->right != NULL){
            temp = temp->right;
        }
        temp->right = new_node;
        new_node->left = temp;
    }
}

// Insert a node at specified position of DLL
void insert_pos(int pos, int val){
    struct dllNode * new_node, *temp, *prev;

    int node_count = count_node(head);
    new_node = create_node(val);

    if(head == NULL){
        head = new_node;
    }
    if(pos < node_count && pos > 0){
        temp = head;
        prev = NULL;
        int i = 0;
        while(i < pos){
            prev = temp;
            temp = temp->right;
            i++;
        }
        prev->right = new_node;
        new_node->right = temp;
        new_node->left = prev;
        temp->left = new_node;
    }
    else{
        printf("Invalid position");
    }
}

// delete a node at begining of DLL
void delete_beg(){
    if(head == NULL){
        printf("List is empty");
    }
    else{
        struct dllNode * temp;
        temp = head;
        head = head->right;
        free(temp);
    }
}

// delete first occurence of node in DLL
void delete_node(int val){
    if(head == NULL){
        printf("List is empty");
    }
    else{
        struct dllNode* temp, *prev;
        temp = head;
        while((temp != NULL)){
            if(temp->data == val){
                // data is at begining
                if(head == temp){
                    head=head->right;
                    head->left = NULL;
                    free(temp);
                    return;
                }
                //data is at end
                else if(temp->right == NULL){
                    (temp->left)->right = NULL;
                    free(temp);
                    return;
                }
                //data is in mid
                else{
                    (temp->left)->right = temp->right;
                    (temp->right)->left = temp->left;
                    free(temp);
                    return;
                }
            }
            temp = temp->right;
        }
    }
}



int main(){
    int ch;
    int pos, val;
    printf("Enter choice\n0. Exit\n1. Insert at beginning\n2. Insert at end\n3. Insert at position\n4. Delete a node\n5. Delete a value first occurence\n");
    scanf("%d", &ch);
    

    while(1){    
        switch (ch)
        {
        case 0:
            printf("Exiting...\n");
            exit(0);
            break;
        case 1:   
            printf("Enter value to insert\n");
            scanf("%d", &val);
            insert_beg(val);
            display();
            break;
        case 2:
            printf("Enter value to insert\n");
            scanf("%d", &val);
            insert_end(val);
            display();
            break;
        case 3:
            printf("Enter value to insert\n");
            scanf("%d", &val);
            printf("Enter position to insert at\n");
            scanf("%d", &pos);
            insert_pos(pos, val);
            display();
            break;
        case 4:
            delete_beg();
            display();
            break;
        case 5:
            printf("Enter value to delete\n");
            scanf("%d", &val);
            delete_node(val);
            display();
        default:
            printf("invalid choice\n\n");
            break;
        }
        printf("Enter choice\n0. Exit\n1. Insert at beginning\n2. Insert at end\n3. Insert at position\n4. Delete a node\n5. Delete a value first occurence\n");
        scanf("%d", &ch);
    }
}
