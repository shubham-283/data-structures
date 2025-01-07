//Circular Doubly Linked List
#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
}*start=NULL,*finish=NULL,*ptr=NULL,*preptr=NULL;

struct node *takeMemory(int data){
    struct node *newNode = (struct node*)malloc(1*(sizeof(struct node)));
    if(newNode==NULL){
        printf("Memory Not Found");
        return 0;
    }
    newNode->prev=NULL;
    newNode->data=data;
    newNode->next=NULL;
}

void createNode(int data){
    struct node *newNode=takeMemory(data);
    if(start==NULL){
        start=finish=newNode;
        newNode->prev=finish;
        newNode->next=start;
    }
    else{
        finish->next=newNode;
        newNode->prev=finish;
        newNode->next=start;
        finish=newNode;
        start->prev=finish;
    }
}


void insertAtBegining(int data){
    if(start==NULL){
        createNode(data);
    }
    else{
        struct node *newNode=takeMemory(data);
        start->prev=newNode;
        newNode->prev=finish;
        newNode->next=start;
        start=newNode;
        finish->next=start;
    }
}


void insertAtLast(int data){
    if(start==NULL){
        createNode(data);
    }
    else{
        struct node *newNode=takeMemory(data);
        finish->next=newNode;
        newNode->prev=finish;
        newNode->next=start;
        finish=newNode;
        start->prev=finish;
    }
}

void insertBefore(int before,int data){
    if(start==NULL){
        createNode(data);
    }
    if(before==start->data){
        insertAtBegining(data);
        return;
    }
    struct node *newNode=takeMemory(data);
    preptr=ptr=start;
    while(preptr->data!=before){
        ptr=preptr;
        preptr=preptr->next;
    }
    ptr->next=newNode;
    newNode->prev=ptr;
    newNode->next=preptr;
    preptr->prev=newNode;
}


void insertAfter(int after,int data){
    if(start==NULL){
        createNode(data);
    }
    if(after==finish->data){
        insertAtLast(data);
        return;
    }
    struct node *newNode=takeMemory(data);
    ptr=start;
    preptr=start->next;
    while(ptr->data!=after){
        ptr=preptr;
        preptr=preptr->next;
    }
    ptr->next=newNode;
    newNode->prev=ptr;
    newNode->next=preptr;
    preptr->prev=newNode;
}


void deleteFirstNode(){
    if(start==NULL){
        printf("\nUNDERFLOW: ALL ELEMENTS ARE DELETED!");
        return;
    }
    if(start==finish){
        free(start);
        start=finish=NULL;
        return;
    }
    finish->next=start->next;
    free(start);
    start=finish->next;
    start->prev=finish;
}


void deleteLastNode(){
    if(start==NULL){
        printf("\nUNDERFLOW: ALL ELEMENTS ARE DELETED!");
        return;
    }
    if(start==finish){
        free(start);
        start=finish=NULL;
        return;
    }
    start->prev=finish->prev;
    free(finish);
    finish=start->prev;
    finish->next=start;
}


void deleteNode(int data){
    if(start==NULL){
        printf("\nUNDERFLOW: ALL ELEMENTS ARE DELETED!");
        return;
    }
    if(start==finish){
        free(start);
        start=finish=NULL;
        return;
    }
    if(start->data==data){
        deleteFirstNode();
        return;
    }
    if(finish->data==data){
        deleteLastNode();
        return;
    }
    preptr=ptr=start;
    while(preptr->data!=data){
        ptr=preptr;
        preptr=preptr->next;
    }
    ptr->next=preptr->next;
    free(preptr);
    preptr=ptr->next;
    preptr->prev=ptr;
}


void updateCDLL(struct node *ptr,int find,int update){
    if(start==NULL){
        printf("Linked List is Empty");
        return;
    }
    else{
        if(ptr->next!=start){
            updateCDLL(ptr->next,find,update);
            if(ptr->data==find){
                ptr->data=update;
                return;
            }
        }
    }
}


void printReverseCDLL(struct node *ptr){
    if(start==NULL){
        printf("Linked List is Empty");
        return;
    }
    else{
        printf("%d\t",ptr->data);
        if(ptr->prev!=finish)
            printReverseCDLL(ptr->prev);
    }
}

void printCDLL(struct node *ptr){
    if(start==NULL){
        printf("Linked List is Empty");
        return;
    }
    else{
        printf("%d\t",ptr->data);
        if(ptr->next!=start)
            printCDLL(ptr->next);
    }
}

int main(){
    createNode(1);
    createNode(2);
    createNode(3);
    createNode(4);
    createNode(5);
    createNode(6);
    createNode(7);
    printCDLL(start);
    printf("\n");
    // printReverseCDLL(finish);
    // insertAtBegining(100);
    // printCDLL(start);
    // printf("\n");
    // printReverseCDLL(finish);
    // printf("\n");
    
    
    // insertAtLast(999);
    // printCDLL(start);
    // printf("\n");
    // printReverseCDLL(finish);
    // printf("\n");
    
    
    // insertBefore(7,55);
    // printCDLL(start);
    // printf("\n");
    // printReverseCDLL(finish);
    // printf("\n");
    // insertAfter(1,66);
    // printCDLL(start);
    // printf("\n");
    // printReverseCDLL(finish);
    // printf("\n");
    
    // deleteFirstNode();
    // printCDLL(start);
    // printf("\n");
    // printReverseCDLL(finish);
    // printf("\n");
    
    // deleteLastNode();
    // printCDLL(start);
    // printf("\n");
    // printReverseCDLL(finish);
    // printf("\n");
    
    // deleteNode(7);
    // printCDLL(start);
    // printf("\n");
    // printReverseCDLL(finish);
    // printf("\n");
    
    
    updateCDLL(start,5,55);
    printCDLL(start);
    printf("\n");
    printReverseCDLL(finish);
    printf("\n");
}
