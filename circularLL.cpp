//circular linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*start=NULL,*finish=NULL,*ptr=NULL,*preptr=NULL;

struct node *takeMemory(int data){
    struct node *newNode = (struct node*)malloc(1*(sizeof(struct node)));
    if(newNode==NULL){
        printf("Memory Not Found");
    }
    else{
        newNode->data=data;
        newNode->next=NULL;
    }
}

int createNode(int data){
    struct node *newNode=takeMemory(data);
    if(start==NULL){
        start=newNode;
        finish=newNode;
        newNode->next=start;
    }
    else{
        newNode->next=start;
        finish->next=newNode;
        finish=newNode;
    }
}

//insert operations
void insertAtBegining(int data){
    struct node* newNode=takeMemory(data);
    if(start==NULL){
        createNode(data);
    }
    else{
        newNode->next=start;
        start=newNode;
        finish->next=start;
    }
}


void insertAtLast(int data){
    struct node* newNode=takeMemory(data);
    if(start==NULL){
        createNode(data);
    }
    else{
        newNode->next=start;
        finish->next=newNode;
        finish=newNode;
    }
}


void insertBefore(int before,int data){
    if(start==NULL){
        createNode(data);
    }
    if(start->data==before){
        insertAtBegining(data);
        return;
    }
    struct node* newNode=takeMemory(data);
    preptr=ptr=start;
    while(preptr->data!=before){
        ptr=preptr;
        preptr=preptr->next;
    }
    ptr->next=newNode;
    newNode->next=preptr;
}


void insertAfter(int after,int data){
    if(start==NULL){
        createNode(data);
    }
    if(start->data==after){
        insertAtLast(data);
        return;
    }
    struct node* newNode=takeMemory(data);
    preptr=ptr=start;
    while(ptr->data!=after){
        ptr=preptr;
        preptr=preptr->next;
    }
    ptr->next=newNode;
    newNode->next=preptr;
}


void deleteFirstNode(){
    if(start==NULL){
        printf("UNDERFLOW");
        return;
    }
    ptr=start;
    if(start==finish)
        start=finish=NULL;
    else{
        start=start->next;
        finish->next=start;
    }
    free(ptr);
}


void deleteLastNode(){
    if(start==NULL){
        printf("UNDERFLOW");
        return;
    }
    ptr=start;
    if(start==finish){
        start=finish=NULL;
    }
    else{
        while(ptr->next!=finish){
            ptr=ptr->next;
        }
        finish=ptr;
        ptr=ptr->next;
        finish->next=start;
    }
    free(ptr);
}


void deleteNode(int data){
    if(start==NULL){
        printf("UNDERFLOW");
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
}


void updateCL(struct node *ptr,int find,int update){
    if(ptr->next!=start){
        updateCL(ptr->next,find,update);
        if(ptr->data==find){
            ptr->data=update;
        }
    }
}


void printReverseCL(struct node *ptr){
    if(ptr->next!=start)
        printReverseCL(ptr->next);
    printf("%d\t",ptr->data);
}


void printCL(){
    if(start==NULL){
        printf("Linked List is Empty");
        return;
    }
    ptr=start;
    while(ptr->next!=start){
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    printf("%d\t",ptr->data);
    ptr=ptr->next;
}

int main(){
    // deleteLastNode();
    // printf("\nlast node deleted\n");
    // printCL();
    
    // deleteFirstNode();
    // printf("\nfirst node deleted\n");
    // printCL();
    
    // insertAtBegining(10);
    createNode(1);
    createNode(2);
    createNode(3);
    // insertAtLast(999);
    
    createNode(4);
    createNode(5);
    printCL();
    printf("\n");
    // printReverseCL(start);
    // insertAtBegining(4);
    // insertAtLast(1000);
    // printCL();
    // printf("\n");
    // deleteLastNode();
    // printf("\nlast node deleted\n");
    // printCL();
    
    // printf("\n");
    // deleteFirstNode();
    // printf("\nfirst node deleted\n");
    // printCL();
    // printf("\n");
    // updateCL(start,6,66);
    // printCL();
    // printf("\n");
    
    // insertBefore(2,22);
    // printCL();
    // printf("\n");
    // insertAfter(4,44);
    // printCL();
    // printf("\n");
    // printReverseCL(start);
    
    deleteNode(3);
    printCL();
    printf("\n");
    deleteNode(2);
    printCL();
    printf("\n");
    
}
