#include <stdio.h>
#include <stdlib.h>


#define MAX 5

int F, R, Count = 0;

int Q[MAX];

void CQInsert();
void CQDelete();
//void rearrangeQ();
void Display();

int main()
{
    printf("\n Circular Queue IMPLEMENTATION \n\n");
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
                CQInsert();
                printf("F = %d R = %d \n", F, R);
                //Display();
                break;
            case 2: 
                CQDelete();    
                printf("F = %d R = %d \n", F, R);
              //  Display();
                break;
            default:
                printf("invalid choice \n");
                break;
        }
       printf("\n Enter Choice \n 1. enqueue \n 2. dequeue \n");
          scanf("%d", &task);
    }
}

void CQInsert()
{
    int x;
    if (Count == MAX)
    {
        printf("C Queue overflow \n");
        
        return;
    }
    else
    {
        printf("\nEnter the element to be added into the queue: ");
        scanf("%d", &x);
        Q[R] = x;
        R = (R+1)%MAX;
        Count++;
    }   
}

void CQDelete(){
    if(Count == 0){
        printf("Queue underflow \n");
        F = 0;
        R  = 0;
        return;
    }
    F = (F+1)%MAX;
    Count--;

}

// void Display(){
//     printf("\n**Queue** \n");
//     int i = F;
//     for(i = F; i < Count || i != R; i= (i+1)%MAX){
//         if()
//         printf("%d ", Q[i]);
//     }
//         //printf("%d ", Q[i]);

//     printf("\n");
// }