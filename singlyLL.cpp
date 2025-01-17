//singly Linked list
#include <stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
} *start=NULL,*finish=NULL,*ptr=NULL,*preptr=NULL,*newNode=NULL;

struct node* takeMemory(int data)
{
    struct node* newNode = (struct node*)malloc(1 * (sizeof(struct node)));
    if(newNode == NULL) {
        printf("Memory not found");
        return 0;
    }
    newNode->data = data;
    newNode->next=NULL;
    //return link;
}
int createNode(int data)
{
    struct node *newNode = takeMemory(data);
    if(start==NULL) {
        start = newNode;
        finish = newNode;
    } else {
        finish->next = newNode;
        finish = newNode;
    }
}
void insertAtBegining(int data){
    if(start==NULL){
        createNode(data);
    }
    else{
        struct node *newNode = takeMemory(data);
        newNode->next = start;
        start=newNode;
    }
}



void insertAtLast(int data){
    if(start== NULL){
        createNode(data);
    }
    else{
        struct node *newNode = takeMemory(data);
        finish->next=newNode;
        newNode->next = NULL;
        finish=newNode;
    }
}


void insertBeforeElement(int before,int data){
    if(start== NULL){
        createNode(data);
    }
    preptr=start;
    ptr=start;
    while(preptr->data!=before){
        ptr=preptr;
        preptr=preptr->next;
    }
    struct node *newNode =takeMemory(data);
    ptr->next=newNode;
    newNode->next=preptr;
}


void insertAfterElement(int after,int data){
    if(start== NULL){
        createNode(data);
    }
    preptr=start;
    ptr=start;
    while(ptr->data!=after){
        ptr=preptr;
        preptr=preptr->next;
    }
    struct node *newNode =takeMemory(data);
    ptr->next=newNode;
    newNode->next=preptr;
}


void deleteNode(int data){
    if(start== NULL){
        printf("UNDERFLOW");
        return;
    }
    preptr=start;
    ptr=start;
    while(preptr->data!=data){
        ptr=preptr;
        preptr=preptr->next;
    }
    if(start==finish)
        start=finish=NULL;
    else{
        ptr->next=preptr->next;
    }
    free(preptr);
    
}
void deleteLast(){
    if(start== NULL){
        printf("UNDERFLOW : ALL ELEMENTS ARE DELETED");
        return;
    }
    ptr=start;
    if(start==finish)
        start=finish=NULL;
    else{
        while(ptr->next!=finish){
            ptr=ptr->next;
        }
        finish=ptr;
	ptr=ptr->next;
        finish->next=NULL;
        
    }
    free(ptr);
}


void deleteFirst(){
    if(start== NULL){
        printf("UNDERFLOW : ALL ELEMENTS ARE DELETED");
        return;
    }
    ptr=start;
    if(start==finish)
        start=finish=NULL;
    else
        start=start->next;
    free(ptr);
}


void updateData(int oldData,int newdata){
    ptr=start;
    while(ptr->data!=oldData)
        ptr=ptr->next;
    ptr->data=newdata;
    printf("value updated\n");
}


void printReverseLL(struct node *ptr){
    if(ptr->next!=NULL)
        printReverseLL(ptr->next);
    printf("%d\t",ptr->data);
}


void printLL()
{
    ptr=start;
Repeat:
    if(ptr!=NULL) {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    } else {
        return;
    }
    goto Repeat;
}

int main()
{
    //insertAtLast(999);
    //insertAtBegining(111);
    createNode(5);
    createNode(6);
    createNode(7);
    createNode(8);
    createNode(9);
    createNode(10);
    printLL();
    printf("\n");

    //updateData(8,100);
    // printLL();

    //insertAtBegining(4);
    //insertAtLast(8);
    //insertBeforeElement(6,555);
    //insertBeforeElement(8,777);
    //insertAfterElement(6,1000);
    //deleteNode(6);
    // deleteLast();
    // printLL();
    // printf("\n");
    // createNode(7);
    // printLL();
    // printf("\n");
    // deleteLast();
    // printLL();
    // printf("\n");
    // deleteLast();
    // printLL();
    // printf("\n");
    // deleteLast();
    // printLL();
    printReverseLL(start);
    
}
