
#include <stdio.h>
#include <stdlib.h>

#define n 10

int top = -1;

int S[n];

void push();
void pop();
void peep();
void change();

int main()
{

    printf("\n STACK IMPLEMENTATION \n\n");
    int task;
    printf("\n Enter Choice\n");

        scanf("%d", &task);
    while(1){
        switch (task) {
            case 0 :
                printf("\nProgram END\n");
                exit(0);
                break;
            case 1: 
                push();
                break;
            case 2: 
            
                pop();    
                break;
            case 3:  
                peep();
                break;
            case 4:
                change();
                break;
            default:
                printf("invalid choice");
                break;
        }
       printf("\n Enter Choice \n\n");
          scanf("%d", &task);
    }


}

void push()
{
    int x;
    if (top >= n)
    {
        printf("Stack overflow");
    }
    else
    {
        printf("\nEnter the element to be added onto the stack: ");
        scanf("%d", &x);
        top = top + 1;
        S[top] = x;
    }
    
}

void pop(){
    if(top == -1) {
        printf("stack underflow on pop");
    }
    else{
        top = top - 1 ;//decrement pointer
        printf("%d", S[top+1]);
    }
}

void peep(){
  
    if(top == -1){
        printf("stack underflow on peep");
    }
    else {
        printf("%d",S[top]);
    }
}

void change(){

    int x;
    if(top == -1){
        printf("stack underflow on change");
    }
    else{
        printf("\nEnter the value to be change into : ");
        scanf("%d", &x);
        S[top] = x;
    }
}




 