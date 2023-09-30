#include <stdio.h>
#include <stdlib.h>


#define MAX 5

int F, R = 0;

int Q[MAX];

void QInsert();
void QDelete();
void rearrangeQ();
void Display();

int main()
{
    printf("\n Queue IMPLEMENTATION \n\n");
    int task;
    printf("\n Enter Choice \n 1. enqueue \n 2. dequeue \n");
        scanf("%d", &task);
    while(1){
        switch (task) {
            case 0 :
                printf("\nProgram END\n");
                exit(0);
                break;
            case 1: 
                QInsert();
                printf("F = %d R = %d \n", F, R);
                Display();
                break;
            case 2: 
                QDelete();    
                printf("F = %d R = %d \n", F, R);
                Display();
                break;
            default:
                printf("invalid choice \n");
                break;
        }
       printf("\n Enter Choice \n 1. enqueue \n 2. dequeue \n");
          scanf("%d", &task);
    }
}

void QInsert()
{
    int x;
    if (R >= MAX && F == 0)
    {
        printf("Queue overflow \n");
        
    }
    else
    {
        printf("\nEnter the element to be added into the queue: ");
        scanf("%d", &x);
        if(R >= MAX && F > 0){
            rearrangeQ();
        }
        Q[R] = x;
        R++;
    }   
}

void QDelete(){
    if(R == 0){
        printf("Queue underflow \n");
        return;
    }
    else if(F == R){
        printf("Queue is empty \n");
        F = 0;
        R = 0;
        return;
    }
    F++;
}

void rearrangeQ(){
    printf( "\nRearranging Queue\n");
    int count = R-F;
  for( int i = 0; i < count; i++){

    Q[i] = Q[F];
    F++;
  }
  R = count;
  F = 0;
}

void Display(){
    printf("\n**Queue** \n");
    for(int i = F; i < R; i++){
        printf("%d ", Q[i]);
    }
    printf("\n");
}