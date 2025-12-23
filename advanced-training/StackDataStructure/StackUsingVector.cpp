#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

class StackDS{
public:
    int max;
    vi st;
    int top;

    StackDS(int size) : max(size), st(size) {
        top = -1;
    }

    bool isFull(){
        return top==max-1;
    }

    bool isEmpty(){
        return top == -1;
    }

    void push(int x){
        if(top == max-1)
            cout<< "Stack Overflow"<<endl;
        else{
            st[++top] = x;
            cout<<"Pushed : "<<x<<endl;
        }
    }

    void pop(){
        if(top==-1)
            cout<<"Stack Underflow"<<endl;
        else
            cout<<"Poped : "<<st[top--]<<endl;
    }

    void peek(){
        if(top == -1)
            cout<<"Stack Underflow"<<endl;
        else
            cout<<"Top Element is :"<<st[top]<<endl;
    }
    int size(){
        return top+1;
    }

};

int main(){
    StackDS s(5);
    s.pop();
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

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


