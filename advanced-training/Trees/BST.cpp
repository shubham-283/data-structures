
//completed - node creation,tree generation, bfs(level Order traversal),dfs(pre order,inOrder, levelOrder traversals)

#include<bits/stdc++.h>

using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;
    
    
    Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};



class BST{
public:
    Node *root=nullptr;
    //replacing old tree with new tree
    void insert(int val){
        root = createTree(root,val);
    }
    
private:
//createTree recursiely
    Node* createTree(Node *root,int val){
        if(!root)
            return new Node(val);
        if(val <= root->data)
            root->left = createTree(root->left,val);
        else
            root->right =createTree(root->right,val);
        return root;
        
    }

};


//height of tree
int heightOfTree(Node *root){
    if(!root) return 0;
    
    int left = 1+heightOfTree(root->left);
    int right = 1+heightOfTree(root->right);
    // int maximum = max(left,right);
    // return maximum;
    return max(left,right);
}




//bfs tarversal
void levelOrder(Node *root){
    if(!root) return;
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        Node* curr = q.front();
        cout<<curr->data<<" ";
        q.pop();
        if(curr->left)
            q.push(curr->left);
        if(curr->right)
            q.push(curr->right);
    }
}
//revursive level order traversals

void levelOrderRecursively(Node* root, vector<vector<int>> & res,int level){
    if(!root) return;
    
    if(res.size()<= level)
        res.push_back({});
    res[level].push_back(root->data);
    
    levelOrderRecursively(root->left,res,level+1);
    levelOrderRecursively(root->right,res,level+1);
    
}







//dfs traversals
void preOrder(Node* root){
    if(!root) return;
    
    cout<< root->data <<" ";
    preOrder(root->left);
    preOrder(root->right);
    
}
void inOrder(Node* root){
    if(!root) return;
    
    
    inOrder(root->left);
    cout<< root->data <<" ";
    inOrder(root->right);
    
}


void postOrder(Node* root){
    if(!root) return;
    
    
    postOrder(root->left);
    postOrder(root->right);
    cout<< root->data <<" ";
}




void printLevelOrderTraversal(Node *root){
    vector<vector<int>> res;
    levelOrderRecursively(root,res,0);
    for(vector<int> x: res){
        for(int i:x){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}


int main(){
    
    BST tree;
    vector<int> vec = {8, 3, 10, 1, 6, 14, 4, 7, 13,1,2,5};
    for(int i:vec){
        tree.insert(i);
    }
    // preOrder(tree.root);
    // levelOrder(tree.root);
    cout<<heightOfTree(tree.root);
    // printLevelOrderTraversal(tree.root);
    
    
}
