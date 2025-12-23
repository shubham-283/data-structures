#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

class QueueVec{
    int front;//to delete
    int rear;//to enter
    vi q;
    int max;//max elements that queue can store

public:

    QueueVec(int maxSize) : front(-1), rear(-1), q(maxSize), max(maxSize) {}

    void enqueue(int x){
        if(rear == max-1){
            cout<<"Queue Overflow"<<endl;
            return;
        }
        if(front == -1 && rear == -1){
            q[++rear] = x;
            front++; 
        }
        else
            q[++rear] =x;
        cout<<"Enqueued : "<<x<<endl;
    }


    void dequeue(){
        if(front == -1){
            cout<<"Queue Underflow"<<endl;
            return;
        }
        if(front == rear){//better to use for space optimization
            cout<<"Dequeued : "<<q[front]<<endl;
            front = rear = -1;
        }
        else
            cout<<"Dequeued : "<<q[front++]<<endl;
    }

    bool isEmpty(){
        return (front == -1);
    }

    bool isFull(){
        return (rear == max-1);
    }

    void peek(){
        if(front==-1)
            cout<<"Queue Underflow"<<endl;
        else
            cout<<"Element at front is : "<<q[front]<<endl;
    }
    
    void getEffectiveSize(){
        if (front == -1)
            cout << "Effective Size: 0" << endl;
        else
            cout << "Effective Size: " << rear - front + 1 << endl;
    }

};

int main(){
    QueueVec myQueue(4);

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