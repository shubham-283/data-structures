//Header Linked List
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
        return 0;
    }
    else{
        newNode->data=data;
        newNode->next=NULL;
    }
}


void createNode(int data){
    struct node *newNode=takeMemory(data);
    if(start==NULL){
        struct node *header = takeMemory(1);
        start=header;
        start->next=newNode;
        finish=newNode;
    }
    else{
        finish->next=newNode;
        finish=newNode;
        start->data++;
    }
}


void insertAtBegining(int data){
    if(start==NULL)
        createNode(data);
    else{
        struct node *newNode=takeMemory(data);
        newNode->next=start->next;
        start->next=newNode;
        start->data++;
    }
    
}


void insertAtLast(int data){
    if(start==NULL)
        createNode(data);
    else{
        struct node *newNode = takeMemory(data);
        finish->next=newNode;
        finish=newNode;
        start->data++;
    }
}


void insertBefore(int before,int data){
    if(start==NULL)
        createNode(data);
    else{
        struct node *newNode = takeMemory(data);
        preptr=ptr=start->next;
        while(preptr->data!=before){
            ptr=preptr;
            preptr=preptr->next;
        }
        ptr->next=newNode;
        newNode->next=preptr;
        start->data++;
    }
}


void insertAfter(int after,int data){
    if(start==NULL)
        createNode(data);
    else{
        struct node *newNode = takeMemory(data);
        preptr=ptr=start->next;
        while(ptr->data!=after){
            ptr=preptr;
            preptr=preptr->next;
        }
        ptr->next=newNode;
        newNode->next=preptr;
        start->data++;
    }
}


void deleteFirstNode(){
    if(start==NULL){
        printf("UNDERFLOW: ALL ELEMENTS ARE DELETED!");
        return;
    }
    ptr=start->next;
    if(start->next==finish){
        free(start);
        start=finish=NULL;
    }
    else{
        start->next=ptr->next;
        start->data--;
    }
    free(ptr);
}


void deleteLastNode(){
    if(start==NULL){
        printf("UNDERFLOW: ALL ELEMENTS ARE DELETED!");
        return;
    }
    ptr=start->next;
    if(start->next==finish){
        free(start);
        start=finish=NULL;
    }
    else{
        while(ptr->next!=finish)
            ptr=ptr->next;
        finish=ptr;
        ptr=ptr->next;
        finish->next=NULL;
        start->data--;
    }
    free(ptr);
}


void deleteNode(int data){
    if(start==NULL){
        printf("UNDERFLOW: ALL ELEMENTS ARE DELETED!");
        return;
    }
    preptr=ptr=start->next;
    if(ptr->data==data){
        deleteFirstNode();
        return;
    }
    if(finish->data==data){
        deleteLastNode();
        return;
    }
    while(preptr->data!=data){
        ptr=preptr;
        preptr=preptr->next;
    }
    ptr->next=preptr->next;
    start->data--;
    free(preptr);
}


void updateHLL(struct node *ptr,int find,int update){
    if(start==NULL){
        printf("\nLinked List is Empty\n");
        return;
    }
    if(ptr->next!=NULL){
        updateHLL(ptr->next,find,update);
        if(ptr->data==find){
            ptr->data=update;
            return;
        }
    }
}


void printReverseHLL(struct node *ptr){
    if(start==NULL){
        printf("\nLinked List is Empty\n");
        return;
    }
    if(ptr->next!=NULL)
        printReverseHLL(ptr->next);
    printf("%d\t",ptr->data);
}



void printHLL(){
    if(start==NULL){
        printf("\nLinked List is Empty\n");
        return;
    }
    ptr=start->next;
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
}




int main(){
    //insertAtBegining(55);
    // deleteFirstNode();
    // printHLL();
    // printf("\n");
    
    // deleteLastNode();
    // printHLL();
    // printf("\n");
    
    //printf("\n%d",start->data);
    createNode(1);
    createNode(2);
    createNode(3);
    createNode(4);
    createNode(5);
    createNode(6);
    createNode(7);
    printHLL();
    printf("\n%d\n",start->data);
    
    // insertAtBegining(100);
    // printHLL();
    // printf("\n");
    // // printf("\n%d",start->data);
    
    
    // insertAtLast(999);
    // printHLL();
    // printf("\n%d",start->data);
    // printf("\n");
    
    // insertBefore(2,283);
    // printHLL();
    // printf("\n");
    // printf("\n%d",start->data);
    
    // insertAfter(2,333);
    // printHLL();
    // printf("\n");
    // printf("\n%d",start->data);
    
    // deleteFirstNode();
    // printHLL();
    // printf("\n%d\n",start->data);
    
    // deleteLastNode();
    // printHLL();
    // printf("\n%d\n",start->data);
    
    // deleteNode(5);
    // printHLL();
    // printf("\n%d\n",start->data);
    
    // deleteNode(2);
    // printHLL();
    // printf("\n%d\n",start->data);
    
    // deleteNode(6);
    // printHLL();
    // printf("\n%d\n",start->data);
    printReverseHLL(start->next);
    
    updateHLL(start->next,5,55);
    printf("\n");
    printHLL();
    printf("\n");
    printf("\n%d\n",start->data);
    printReverseHLL(start->next);
}
