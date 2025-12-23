#include<bits/stdc++.h>

using namespace std;
class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

class StackLL{
    int size;
    Node *top;


public:

    StackLL() : size(0), top(nullptr){}


    //(Destructor)Optional , but better to use for preventing memory leaks
    ~StackLL(){
        cout << "Clearing Memory..." << endl;
        while(top){
            Node* temp = top;
            top = top->next;
            delete temp;
        }
        size =0;
    }

    void push(int x){
        try{
            Node *newNode = new Node(x);
            newNode->next = top;
            top = newNode;
            size++;
            cout<<"Pushed : "<<x<<endl;
        }
        catch (bad_alloc& e) {
            cout << "Stack Overflow" << endl;
        }
    }

    void pop(){
        if(!top)
            cout<<"Stack Underflow"<<endl;
        else{
            Node* temp = top;
            top = top->next;
            cout<<"Poped : "<<temp->data<<endl;
            delete temp;
            size--;
        }
    }

    void peek(){
        if(!top)
            cout<<"Stack Underflow"<<endl;
        else
            cout<<"Top : "<<top->data<<endl;
    }
    bool isEmpty(){
        return !top;
    }

    void stackSize(){
        cout<<"Size : "<<size<<endl;
    }

};

int main(){
    StackLL s;
    (s.isEmpty())? cout<<"Empty"<<endl : cout<<"Not Empty"<<endl;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    (s.isEmpty())? cout<<"Empty"<<endl : cout<<"Not Empty"<<endl;
    s.peek();
    s.pop();
    s.peek();
    s.pop();
    s.peek();
    s.pop();
    s.peek();
    s.pop();
    s.peek();
    s.pop();
    s.peek();
    s.pop();

}