//BST
#include<stdio.h>
#include<iostream>
using namespace std;

struct node{
    struct node* left;
    int data;
    struct node* right;
}*root=NULL;

struct node *takeMemory(int data){
    struct node *root = new struct node;
    if(root == NULL){
        cout<<"Memory Not Found";
        return root;
    }
    root->data=data;
    root->left=NULL;
    root->right=NULL;
    return root;
}

int heightOfTree(struct node* root) {
    if (root == NULL){
        return 0;
    }
    return 1 + max(heightOfTree(root->left), heightOfTree(root->right));
}

struct node* leftRotation(struct node *root){
    struct node *Temp = root->right;
    struct node * Temp2 = Temp->left;
    
    Temp->left = root;
    root->right = Temp2;
    
    return Temp;
}

struct node* rightRotation(struct node *root){
    struct node *Temp = root->left;
    struct node * Temp2 = Temp->right;
    
    Temp->right = root;
    root->left= Temp2;
    return Temp;
}

struct node *AVLTree(struct node *root){
    int balance = heightOfTree(root->left) - heightOfTree(root->right);
    if(balance > 1){
        if (heightOfTree(root->left->right) > heightOfTree(root->left->left)) {
            root->left = leftRotation(root->left);
        }
        return rightRotation(root);
    }
    else if(balance < -1){
        if (heightOfTree(root->right->left) > heightOfTree(root->right->right)) {
            root->right = rightRotation(root->right);
        }
        return leftRotation(root);
    }
    return root;
}




struct node *createTree(struct node *root,int data){
    if(root == NULL)
        return takeMemory(data);
    else if(data < root->data)
        root->left = createTree(root->left,data);
    else
        root->right = createTree(root->right,data);
    return AVLTree(root);
    // return root;
}


//below function is requied because if we repeatedly calls the createTree() then it will create new tree every time.
struct node *insertLeaf(int data){
    root=createTree(root,data);
    return root;
}


//ROOT > LEFT > RIGHT
void preOrder(struct node *root){
    if(root==NULL)
        return;
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}

//LEFT > RIGHT > ROOT
void postOrder(struct node *root){
    if(root==NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->data);
}

//LEFT > ROOT > RIGHT
void inOrder(struct node *root){
    if(root==NULL)
        return;
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}

void search(struct node *root,int data){
    if(root==NULL || (root->left == NULL && root->right == NULL)){
        cout<<"Element not found";
        return;
    }
    else if(root->data==data)
        cout<<"Element Found";
    else if(data < root->data)
        search(root->left,data);
    else
        search(root->right,data);
}


struct node* searchNode(struct node *root,int data){
    if(root==NULL )
        return NULL;
    else if(root->left == NULL && root->right == NULL && root->data==data)
        return root;
    else if(root->data==data)
        return root;
    else if(data < root->data)
        return searchNode(root->left,data);
    else
        return searchNode(root->right,data);
}



//to search the parent node for a given child and delete that node
struct node* parentSearch(struct node *root,int data){
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return NULL;
        
    if(root->data == data)
        return root;
    else if ((root->left != NULL && root->left->data == data) || 
        (root->right != NULL && root->right->data == data))
        return root;
    else if(root->left->data==data || root->right->data==data)
        return root;
    else if(data < root->data)
        return parentSearch(root->left,data);
    else
        return parentSearch(root->right,data);
}


//deleting leaf nodes or we can say the nodes which have 0 child
void deleteLeafNode(struct node *root,int data){
    struct node* parentNode = parentSearch(root,data);
    if(parentNode == NULL){
        printf("Element Not Found\n");
        return;
    }
    if (parentNode->left != NULL && parentNode->left->data == data) {
        if (parentNode->left->left == NULL && parentNode->left->right == NULL) {
            printf("%d is deleted.\n",parentNode->left->data);
            delete parentNode->left;
            parentNode->left=NULL;
        }
        else {
            printf("Element is not a leaf node.\n");
        }
    }
    else if(parentNode->right != NULL && parentNode->right->data == data) {
        if (parentNode->right->left == NULL && parentNode->right->right == NULL) {
            printf("%d is deleted.\n",parentNode->right->data);
            delete parentNode->right;
            parentNode->right=NULL;
        }
        else {
            printf("Element is not a leaf node.\n");
        }
    } else {
        printf("Element not found.\n");
    }
}


//deleting Nodes which have single child
void deleteNodeWithSingleChild(struct node* root,int data){
    struct node* currentNode = searchNode(root,data);
    if(currentNode == NULL){
        printf("Element Not Found\n");
        return;
    }
    if(currentNode->left != NULL && currentNode->right != NULL){
        printf("Element has more than 1 leaf Node.\n");
    }
    else if(currentNode->left != NULL){
        printf("%d is deleted.\n",currentNode->data);
        currentNode->data=currentNode->left->data;
        delete currentNode->left;
        currentNode->left=NULL;
    }
    else if(currentNode->right !=NULL){
        printf("%d is deleted.\n",currentNode->data);
        currentNode->data=currentNode->right->data;
        delete currentNode->right;
        currentNode->right=NULL;
    }
    else {
        printf("Element not found.\n");
    }
}




struct node* successor(struct node* root){
    if(root==NULL)
        return NULL;
    else if(root->left == NULL)
        return root;
    else
        return successor(root->left);
}


//successor code

//for root with one or two child(used to delete nodes with 2 child)
struct node* successorNode(int data) {
    struct node *link = searchNode(root, data);
    if (link == NULL)
        return NULL;
    else if (link->right == NULL)
        return NULL;
    else if (link->right->left == NULL)
        return link->right;
    else {
        link = successor(link->right);
        return link;
    }
}

//for zero child
int successorOfLeaf(struct node* root,int data){
    struct node* Temp = parentSearch(root,data);
    if(Temp->data>data){
        return Temp->data;
    }
    else
        return successorOfLeaf(root,Temp->data);
}

void success(struct node* root,int data){
    struct node *link= searchNode(root,data);
    if(link == NULL)
        printf("Successor Not Found\n");
    else if(link->left == NULL && link->right == NULL){
         printf("%d\n",successorOfLeaf(root,data));
    }
    else if(link->right == NULL)
        printf("successor Not Found\n");
    else if(link->right->left == NULL)
        printf("%d\n",link->right->data);
    else{
        link = successor(link->right);
        if(link!= NULL)
            printf("%d\n",link->data);
    }
}



void deleteNodeWithTwoChild(struct node* root,int data){
    struct node* successor_node = successorNode(data);//gives successor node51
    struct node* delete_data = searchNode(root,data);//gives node to be deleted 46
    if(successor_node == NULL){
        printf("Deletion not possible as successor not Found.\n");
        return;
    }
    delete_data->data = successor_node->data;
    if(successor_node->left == NULL && successor_node->right== NULL)
        return deleteLeafNode(delete_data,successor_node->data);
    else
        return deleteNodeWithSingleChild(successor_node,successor_node->data);
}



int main(){
    insertLeaf(1);
    insertLeaf(2);
    insertLeaf(3);
    insertLeaf(4);
    insertLeaf(5);
    insertLeaf(6);
    insertLeaf(7);
    insertLeaf(8);
    insertLeaf(9);
    insertLeaf(10);
    insertLeaf(11);
    insertLeaf(12);
    insertLeaf(13);
    insertLeaf(14);
    insertLeaf(15);
    
    
    
    // insertLeaf(36);
    // insertLeaf(26);
    // insertLeaf(46);
    // insertLeaf(21);
    // insertLeaf(31);
    // insertLeaf(11);
    // insertLeaf(24);
    // insertLeaf(41);
    // insertLeaf(56);
    // insertLeaf(51);
    // insertLeaf(66);
    // insertLeaf(10);
    // insertLeaf(25);
    // insertLeaf(55);
    // insertLeaf(60);
    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);
    
    printf("\n");
    // printf("%d \n",searchNode(root,55)->data);
    // printf("\n");
    struct node* result = parentSearch(root,15);
    printf("parent = %d \n",result->data);
    
    printf("left child = %d  & right child = %d \n",result->left->data,result->right->data);
    
    //deleteLeafNode(result,60);
    
    //deleteNodeWithSingleChild(root,51);
    printf("\n");
    //result = parentSearch(root,56);
    //printf("parent = %d \n",result->data);
    // inOrder(root);
    // printf("\n");
    //success(root,);
    // result = successorNode(51);
    // printf("parent = %d \n",result->data);
    // deleteNodeWithTwoChild(root,55);
    printf("\n");
    inOrder(root);
    printf("\nheight of tree = %d",heightOfTree(root));
    //printf("succesor of leaf = %d\n",successorOfLeaf(root,55));
}

