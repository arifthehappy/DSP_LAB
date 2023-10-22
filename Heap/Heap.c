#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void heapify(int arr[], int n, int i){
    int left = 2*i+1;
    int right = 2*i+2;
    int max = i;

    if(arr[max] < arr[left] && left < n){
        max = left;
    }
    if(arr[max] < arr[right] && right < n){
        max = right;
    }
    //max pos is changed
    if(max != i){
        int temp;
        temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
        heapify(arr,n, max); 
    }
}

void insertHeapElement(int arr[], int n){

}

void buildMaxHeap(int arr[], int n){
    for(int i = (n/2)-1; i>=0; i --){
        heapify(arr,n,i);
    }
}

void printHeap(int arr[], int n){
    int i = 0;
    int ch1 = i*2 + 1;
    int ch2 = i*2 + 2;
    int level = 1;


    for( i = 0; i < n; i++){
        if(i == (pow(2,level)-2))
        printf("\n");
        printf("%d  ", arr[i]);
    }
}

void heapSort(int arr[], int n){
    buildMaxHeap(arr,n);
    for(int i = n-1; i>=0;i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr,i,0);
    }
}


int main(){

    int arr[10] = {100,123,122,141,143,244,234,54,23,423};
    int n = sizeof(arr)/sizeof(int);

    buildMaxHeap(arr, n);
    printHeap(arr,n);
    heapSort(arr,n);
    printHeap(arr,n);



    return 0;
}