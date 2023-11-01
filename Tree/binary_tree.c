#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node * rightChild;
    int data;
    struct node *leftChild;
};



// creating a node
struct node *create_node(int val){
    struct node *new_node;
    new_node = (struct node *) malloc(sizeof(struct node));
    new_node->rightChild = NULL;
    new_node->data = val;
    new_node->leftChild = NULL;
    return new_node;
}

void inorderTraversal(struct node * root);
void preorderTraversal(struct node * root);
void postorderTraversal(struct node* root);
void printCurrentLevel(struct node * root, int level);
int height(struct node* node);

int main()
{
    struct node* root = create_node(1);

    root->leftChild = create_node(2);
    root->rightChild = create_node(3);

    root->leftChild->leftChild = create_node(4);

    root->rightChild->leftChild = create_node(5);
    root->rightChild->rightChild = create_node(6);

    root->leftChild->leftChild->rightChild = create_node(7);

    root->rightChild->leftChild->leftChild = create_node(8);
    root->rightChild->leftChild->rightChild = create_node(9);


    printf("inorder: ");

    inorderTraversal(root);
    printf("\n");
    printf("preorder: ");

    preorderTraversal(root);
    printf("\n");
    printf("postorder: ");
    postorderTraversal(root);
    printf("\n");
    printf("level order: \n");
    printLevelOrder(root);


}

void inorderTraversal(struct node * root){
    if(root != NULL){
        inorderTraversal(root->leftChild);
        printf("%d ", root->data);
        inorderTraversal(root->rightChild);
    }
}

void preorderTraversal(struct node * root){
    if(root != NULL){
        printf("%d ", root->data);
        preorderTraversal(root->leftChild);
        preorderTraversal(root->rightChild);
    }
}

void postorderTraversal(struct node* root){
    if(root != NULL){
        postorderTraversal(root->leftChild);
        postorderTraversal(root->rightChild);
        printf("%d ", root->data);
    }
}



void printGivenLevel(struct node* root, int level){
    if(root == NULL)
        return;
    if(level == 1)
        printf(" %d ", root->data);
    else if(level > 1){
        printGivenLevel(root->leftChild, level - 1);
        printGivenLevel(root->rightChild, level - 1);
    }
}

void printLevelOrder(struct node* root){
    int h = height(root);
    int i;
    for(i = 1; i <= h; i++){
        printGivenLevel(root, i);
    }
    printf("\n");
}

int height(struct node* node){
    if(node == NULL)
        return 0;
    else{
        int lheight = height(node->leftChild);
        int rheight = height(node->rightChild);

        if(lheight > rheight){
            return (lheight + 1);
        }
        else{
            return (rheight +  1);
        }
    }
}