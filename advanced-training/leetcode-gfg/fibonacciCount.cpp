#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

void fibo(vi &v,int sum){
    v.push_back(1);
    v.push_back(1);
    for(int i=2;(v[i-1]+v[i-2])<=sum;i++){
        v.push_back(v[i-1]+v[i-2]);
    }
}


//with dynamic programming
void minCount(int sum,int &count,int currCount, vi &v, int index, int n){
    if(sum==0 && currCount){
        count = min(count,currCount);
        return;
    }
    if(index>=n || sum<0)
        return;
    
    int temp = v[index];
    minCount(sum-temp,count,currCount+1,v,index+1,n);
    minCount(sum,count,currCount,v,index+1,n);
}

//without dp
int minCountOptimized(int sum,int index,vi &fib){
    int count=0;

    while(sum>0){
        if(fib[index] <= sum){
            sum-=fib[index];
            count++;
        }
        index--;
    }
    return count;
}



int main(){
    int sum;
    cin>>sum;
    vi fib;
    fibo(fib,sum);
    for(int &i : fib){
        cout<<i<<" ";
    }
    
    
    cout<<endl;
    
    
    // int count= INT_MAX;
    
    // minCount(sum,count,0,fib,1,fib.size());
    // cout<<count;
    
    cout<< minCountOptimized(sum,fib.size()-1,fib);
}