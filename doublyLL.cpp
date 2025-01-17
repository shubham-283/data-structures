//Doubly Linked List
#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
}*start=NULL,*finish=NULL,*ptr=NULL,*preptr=NULL,*temp=NULL;


struct node *takeMemory(int data){
    struct node *newNode = (struct node*)malloc(1*(sizeof(struct node)));
    if(newNode==NULL){
        printf("Memory Not Found");
    }
    else{
        newNode->prev=NULL;
        newNode->data=data;
        newNode->next=NULL;
    }
}


void createNode(int data){
    struct node *newNode = takeMemory(data);
    if(start==NULL){
        start=newNode;
        finish=newNode;
    }
    else{
        finish->next=newNode;
        newNode->prev=finish;
        finish=newNode;
    }
}


int insertAtBegining(int data){
    if(start==NULL){
        createNode(data);
    }
    else{
        struct node *newNode = takeMemory(data);
        start->prev=newNode;
        newNode->next=start;
        start=newNode;
    }
}


int insertAtLast(int data){
    if(start==NULL){
        createNode(data);
    }
    else{
        struct node *newNode = takeMemory(data);
        finish->next=newNode;
        newNode->prev=finish;
        finish=newNode;
    }
}


int insertBefore(int before,int data){
    if(start==NULL){
        createNode(data);
    }
    else{
        struct node *newNode = takeMemory(data);
        ptr=start;
        preptr=start;
        while(preptr->data!=before){
            ptr=preptr;
            preptr=preptr->next;
        }
        ptr->next=newNode;
        newNode->prev=ptr;
        newNode->next=preptr;
        preptr->prev=newNode;
    }
}


int insertAfter(int after,int data){
    if(start==NULL){
        createNode(data);
    }
    else{
        struct node *newNode = takeMemory(data);
        ptr=start;
        preptr=start;
        while(ptr->data!=after){
            ptr=preptr;
            preptr=preptr->next;
        }
        ptr->next=newNode;
        newNode->prev=ptr;
        newNode->next=preptr;
        preptr->prev=newNode;
    }
}


void deleteFirstNode(){
    if(start==NULL){
        printf("\nUNDERFLOW\n");
        return;
    }
    ptr=start;
    if(start==finish)
        start=finish=NULL;
    else{
        start=start->next;
        start->prev=NULL;
    }
    free(ptr);
    
}


void deleteLastNode(){
    if(start==NULL){
        printf("\nUNDERFLOW\n");
        return;
    }
    ptr=finish;
    if(start==finish)
        start=finish=NULL;
    else{
        finish=finish->prev;
        finish->next=NULL;
    }
    free(ptr);
    
}


void deleteNode(int data){
    if(start==NULL){
        printf("\nUNDERFLOW: ALL ELEMENTS ARE DELETED\n");
        return;
    }
    if(finish->data==data){
        deleteLastNode();
        return;
    }
    if(start->data==data){
        deleteFirstNode();
        return;
    }
    temp=preptr=ptr=start;
    if(start==finish)
        start=finish=NULL;
    else{
        while(preptr->data!=data){
            ptr=preptr;
            preptr=preptr->next;
        }
        ptr->next=preptr->next;
        temp=preptr;
        preptr=preptr->next;
        preptr->prev=ptr;
    }
    free(temp);
}

void updateDL(int find,int update){
    ptr=start;
    while(ptr->data!=find)
        ptr=ptr->next;
    ptr->data=update;
}

void printDL(){
    ptr=start;
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
}


void reversePrintDL(){
    ptr=finish;
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->prev;
    }
}

int main(){
    createNode(1);
    createNode(2);
    createNode(3);
    createNode(4);
    createNode(5);
    printDL();
    printf("\n");
    //reversePrintDL();
    // insertAtBegining(100);
    // printDL();
    // printf("\n");
    // reversePrintDL();
    printf("\n");
    
    // insertAtLast(1000);
    // printDL();
    // printf("\n");
    // reversePrintDL();
    // printf("\n");
    // insertBefore(4,100);
    // printDL();
    // printf("\n");
    // reversePrintDL();
    // printf("\n");
    
    // insertAfter(4,200);
    // printDL();
    // printf("\n");
    // reversePrintDL();
    // printf("\n");
    
    // deleteFirstNode();
    // printDL();
    // printf("\n");
    // reversePrintDL();
    // printf("\n");
    
    // deleteLastNode();
    // deleteLastNode();
    // deleteLastNode();
    // printDL();
    // printf("\n");
    // deleteLastNode();
    // printDL();
    // printf("\n");
    // reversePrintDL();
    // printf("\n");
    
    // deleteNode(4);
    // printDL();
    // printf("\n");
    // deleteNode(5);
    // deleteLastNode();
    // printDL();
    // printf("\n");
    // deleteNode(1);
    // printDL();
    // printf("\n");
    // deleteNode(3);
    // printDL();
    // printf("\n");
    
    updateDL(3,33);
    printDL();
    printf("\n");
    reversePrintDL();
}
