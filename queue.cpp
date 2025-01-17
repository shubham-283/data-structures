//QUEUE
#include<stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 20
int rear=-1,front=-1;

void enqueue(int* queue,int val){
    if(rear==MAX-1){
        printf("\nOVERFLOW\n");
        return;
    }
    if(rear==-1 && front==-1){
        queue[++rear]=val;
        front++;
    }
    else{
        queue[++rear]=val;
    }
}

int dequeue(int* queue){
    if(rear==-1){
        printf("\nUNDERFLOW\n");
        return -1;
    }
    if(front==rear){
        printf("\n%d is deleted.",queue[front]);
        front=rear=-1;
    }
    else{
        printf("\n%d is deleted.",queue[front]);
        front++;
    }
}

int peek(int* queue){
    if(front==-1){
        printf("\nQueue is Empty.\n");
        return 0;
    }
    return queue[front];
}

void printQueue(int* queue){
    if(rear==-1){
        printf("\nUNDERFLOW\n");
        return;
    }
    for(int i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
}

bool isEmpty(){
    return rear==-1;
}
bool isFull(){
    return rear==MAX-1;
}

int main(){
    int* queue = calloc(MAX,sizeof(int));
    //printf("\n%d \n",peek(queue));
    printf("%d\n",isEmpty());
    enqueue(queue,1);
    enqueue(queue,2);
    enqueue(queue,3);
    enqueue(queue,4);
    enqueue(queue,5);
    enqueue(queue,6);
    printQueue(queue);
    printf("\n%d \n",peek(queue));
    dequeue(queue);
    dequeue(queue);
    printQueue(queue);
    printf("\n%d \n",peek(queue));
    
    
    
    free(queue);
}
