#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}node;

struct node *head = NULL;

// display single linked list
void display(){
    struct node *temp;
    temp = head;
    printf("\nList is: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// creating a node
struct node *create_node(int val){
    struct node *new_node;
    new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = val;
    new_node->next = NULL;
    return new_node;
}

//count number of nodes
int count_node(struct node *head){
    int count = 0;
    struct node *temp;
    temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;

    }
    return count;
}

// insert a node at the beginning
void insert_beg(int val){
    struct node * new_node;
    new_node = create_node(val);
    if(head == NULL){
        head = new_node;
    }
    else{
        new_node -> next = head;
        head = new_node;
    }
}

// insert a node at the position of single linked list
void insert_pos(int pos, int val){
    struct node * new_node;
    struct node * temp;
    struct node * prev;
    int node_count = count_node(head);
    new_node = create_node(val);

    if(pos < node_count && pos > 0){
        temp = head;
        prev = NULL;
        int i = 0;
        while(i < pos){
            prev = temp;
            temp = temp->next;
            i++;

        }
        prev->next = new_node;
        new_node->next = temp;
    }
    else{
        printf("Invalid position");
    }
}

// insert a node at the end
void insert_end(int val){
    struct node * new_node;
    new_node = create_node(val);
    if(head == NULL){
        head = new_node;
    }
    else {
        struct node * temp;
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
            
        }
        temp->next = new_node;
    }
}

// delete a node at beginning
void delete_beg(){
    if(head == NULL){
        printf("List is empty");
    }
    else{
        struct node * temp;
        temp = head;
        head = head->next;
        free(temp);
    }
}

// delete a node at the position of single lined list
void delete_pos(int pos){
    struct node * temp, *prev;
    int node_count = count_node(head);
    if(head ==  NULL){
        printf("List is empty");
    }
    else{
        if(pos < node_count && pos > 0){
            temp = head;
            prev = NULL;
            int i = 0;
            while(i < pos){
                prev = temp;
                temp = temp->next;
                i++;
            }
            prev->next = temp->next;
            free(temp);
            printf("Deleted");
        }
        else{
            printf("Invalid position");
        }
    }
}

int main(){
    int ch;
    int pos, val;
    printf("Enter choice\n0. Exit\n1. Insert at beginning\n2. Insert at end\n3. Insert at position\n4. Delete at beginning\n5. Delete at position\n\n");
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
            
            printf("Enter position to delete\n");
            scanf("%d", &pos);
            delete_pos(pos);
            display();
            break;
        default:
            break;
        }
        printf("Enter choice\n0. Exit\n1. Insert at beginning\n2. Insert at end\n3. Insert at position\n4. Delete at beginning\n5. Delete at position\n\n");
        scanf("%d", &ch);
    }
}