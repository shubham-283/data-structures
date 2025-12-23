#include<bits/stdc++.h>

using namespace std;
typedef vector<bool> vb;
typedef vector<long long> vll;


void sieve(vb &isPrime,long long n){
    isPrime[0]=isPrime[1] = false;
    
    for(long long i=2;i*i<=n;i++){
        if(isPrime[i]){
            for(long long j=i*i;j<=n;j+=i)
                isPrime[j]=false;
        }
    }
}


int main(){
    long long n;
    
    cin>>n;
    
    vb isPrime(n+1,true);
    sieve(isPrime,n);
    vll primes;
    vll prefixSum;
    
    
    long long sum=0;
    for(long long i=0;i<=n;i++){
        if(isPrime[i]){
            primes.push_back(i);
            sum += i;
            if(sum == 2 || sum&1)
                prefixSum.push_back(sum);
        }
    }
    
    //prefixSum
    // for(int i=1;i<primes.size();i++){
    //     primes[i] += primes[i-1];
    // }
    int count = 0;
    for (int i = 1; i < prefixSum.size(); i++) {
        long long num = prefixSum[i];
        long long range = sqrt(num);
        bool flag = false;
        // if(prefixSum[i]>n) break;
        for (int j = 0; j < primes.size() && primes[j] <= range; j++) {
            if (num % primes[j] == 0) {
                flag = true;
                break;
            }
        }
    
        if (!flag) {
            cout << num << " ";
            count++;
        }
    }
    cout << "\nCount = " << count;

    
}