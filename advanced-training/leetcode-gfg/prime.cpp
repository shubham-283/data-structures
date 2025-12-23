// Online C++ compiler to run C++ program online
#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int num){
    if(num==1)
        return false;
    for(int i=2;i<= sqrt(num);i++){
        if(num%i == 0){
            return false;
        }
    }
    return true;
}

bool isPrimeFaster(int num){
    if(num<=1)
        return false;
    if(num ==2)
        return true;
    if(num%2==0)
        return false;
    for(int i=3;i<= num/i;i+=2){
        // printf("%d ",i);
        if(num%i == 0){
            return false;
        }
    }
    return true;
}//O(n^1/2)


void main() {
    int num=0;
    cin>>num;
    int i=0;
    cout<<"List of Prime: \n";
    while(i<=num){
        if(isPrimeFaster(i)){
            printf("%d ",i);
        }
        i++;
    }
    cout<<"\nNumber " << num <<" is Prime: "<<(isPrimeFaster(num) ? "true" : "false")<<endl;
}
