// #include<bits/stdc++.h>
// #define MAX 10000001
// using namespace std;
// typedef vector<int> vi;
// typedef vector<bool> vb;
// typedef vector<pair<int,int>> vpii;
// typedef pair<int,int> pii;







// void sieve(vb &isPrime,int n){
//     isPrime[0]=isPrime[1]=false;
//     for(int i=2;i<=n/i;i++)
//         if(isPrime[i]==true)
//             for(int j=i*i;j<=n;j+=i)
//                 isPrime[j] = false;
// }


// void merge_queries(vpii &queries,vi &merge_query){
//     int m = queries.size();
//     for(int i=0;i<m;i++){
//         merge_query[queries[i].first]++;
//         merge_query[queries[i].second+1]--;
//     }
//     // for(int i=0;i<MAX-1;i++){
//     //     merge_query[i+1] += merge_query[i];
//     // }
// }





// int main(){
//     int m;//number of queries
//     cin>>m;
//     vpii queries(m);
//     int min = INT_MAX;
//     int max = INT_MIN;
//     for(int i=0;i<m;i++){
//         cin>>queries[i].first >> queries[i].second;
//         if(min>queries[i].first)
//             min = queries[i].first;
//         if(max<queries[i].second)
//             max = queries[i].second;
//     }
    
//     vi merge_query(MAX,0);
//     merge_queries(queries,merge_query);
//     // cout<<"done";
//     vb isPrime(MAX,true);
//     sieve(isPrime,MAX);
    
//     // for(int x : merge_query){
//     //     cout<<x<<" ";
//     // }
//     for(int i=min;i<=max;i++){
//         merge_query[i+1] += merge_query[i];
//         if(merge_query[i] && isPrime[i])
//             cout<<i<< " ";
//     }
    
    
    
// }



#include <bits/stdc++.h>
using namespace std;
    
void sieve(vector<bool> &isPrime, int n) {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i])
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;
    vector<pair<int,int>> queries(m);
    int minL = INT_MAX, maxR = INT_MIN;

    for (auto &q : queries) {
        cin >> q.first >> q.second;
        minL = min(minL, q.first);
        maxR = max(maxR, q.second);
    }

    int range = maxR - minL + 2;
    vector<int> merge_query(range, 0);

    for (auto &q : queries) {
        int l = q.first;
        int r = q.second;
        merge_query[l - minL]++;
        merge_query[r - minL + 1]--;
    }


    for (int i = 1; i < range; i++)
        merge_query[i] += merge_query[i - 1];

    vector<bool> isPrime(maxR + 1, true);
    sieve(isPrime, maxR);

    for (int i = minL; i <= maxR; i++)
        if (merge_query[i - minL] > 0 && isPrime[i])
            cout << i << endl;
}
