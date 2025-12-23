#include<bits/stdc++.h>

using namespace std;
typedef vector<bool> vb;
typedef vector<int> vi;



int reverseNum(int n){//log10(n)
    int rev=0;
    while(n){
        rev = (rev*10) + n%10;
        n/=10;
    }
    return rev;
}


void sieve(vb &isPrime,int n){//nloglog(n)
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i<=n/2;i++)
        if(isPrime[i]==true)
            for(int j=i*i;j<=n;j+=i)
                isPrime[j] = false;
}

bool satisfies(int num, vi &primeRank){//log10(n)  k=2
    int rev =reverseNum(num);//log10(n)
    if(primeRank[num] && primeRank[rev]){
        int r1 =primeRank[num];
        int r2 = reverseNum(r1);//log10(n)
        return r2==primeRank[rev];
    } 
    return false;
}



int main(){
    cout<<"Enter n: ";
    int n;
    cin>>n;
    
    vb isPrime(n+1,true);
    sieve(isPrime,n);//nloglog(n)
    vi primeRank(n+1,0);
    
    int rank=1;
    for(int i=2;i<=n;i++)//n
        if(isPrime[i])
            primeRank[i]=rank++;
    
    
    
    for(int i=12;i<=n;i++)//n
        if(satisfies(i,primeRank))
            cout<<i<<"\t";
}