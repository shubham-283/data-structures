#include<bits/stdc++.h>
using namespace std;
int countBits(int n){
    int count=0;
    while(n){
        count++;
        n= n>>1;
    }
    return count;
}
int SetBitCount(int n){
    int count=0;
    while(n){
        if (n&1)
            count++;
        n= n>>1;
    }
    return count;
}


void swapNumbers(int &a, int &b){
    a = a^b;
    b = a^b;
    a = a^b;
}


int main(){
    int n;
    cin>>n;
    cout<< countBits(n)<<endl;
    cout << ceil(log2(n));//mathematical form
    cout << SetBitCount(n) << endl;
}