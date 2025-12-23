#include<bits/stdc++.h>

using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val): data(val),next(nullptr){}
};

class QueueLL{
    Node* front;//to  delete elements
    Node* rear;//to enter elements
    int size;
public:
    //Contructor
    QueueLL(): front(nullptr),rear(nullptr),size(0){}
    
    //(Destructor)Optional , but better to use for preventing memory leaks
    ~QueueLL() {
        cout <<endl<<"Clearing Memory..." << endl;
        while (front) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
        size = 0;
    }


    void enqueue(int val){
        try{
            Node* newNode = new Node(val);
            if(!rear)
                front = rear = newNode;
            else{
                rear->next = newNode;
                rear = newNode;
            }
            size++;
            cout<<"Endueued :"<< val<<endl;
        }
        catch (bad_alloc& e) {
            cout << "Queue Overflow" << endl;
        }
        
    }

    void dequeue(){
        if(!front){
            cout<<"Queue Underflow"<<endl;
            return;
        }
        Node* temp = front;
        if(front == rear)
            front = rear = nullptr;
        else
            front = front->next;
        size--;
        cout<<"Dequeued : "<<temp->data<<endl;
        delete temp;
    }

    bool isEmpty(){
        return (!rear);
    }

    void peek(){
        if(!front)
            cout<<"Queue Underflow"<<endl;
        else
            cout<<"Element at front is : "<<front->data<<endl;
    }

    void getEffectiveSize(){
        cout<<"Effective Size : "<<size<<endl;
    }

};

int main(){
    QueueLL myQueue;

    myQueue.getEffectiveSize();

    myQueue.enqueue(100);
    myQueue.enqueue(200);
    myQueue.enqueue(300);
    myQueue.enqueue(400);
    myQueue.getEffectiveSize();
    myQueue.enqueue(500); 

    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.getEffectiveSize();

    myQueue.dequeue();
   
    myQueue.getEffectiveSize();
    myQueue.dequeue();
    myQueue.getEffectiveSize();

    myQueue.enqueue(10);
    myQueue.dequeue();
    myQueue.enqueue(20);
    myQueue.dequeue();
    myQueue.enqueue(30);
    myQueue.enqueue(40);
    myQueue.getEffectiveSize(); 
    
    myQueue.dequeue(); 
    myQueue.dequeue();
    myQueue.dequeue();
}