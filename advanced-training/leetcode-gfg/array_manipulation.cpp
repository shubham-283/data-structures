#include<bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;


long arrayManipulation(int n, vvi queries) {
    vi nums(n+2,0);
    for(vi &query: queries){
        int a = query[0]-1;
        int b = query[1]-1;
        nums[a]+=query[2];
        if(b+1<=n){
            nums[b+1]-=query[2];
        }
    }
    long max=0;
    long curr=0;
    for(int i=0;i<=n;i++){
        curr+=nums[i];
        if(curr>max)
            max=curr;
    }
    return max;
}




void main() {
    int n, q;
    cout << "Enter size: ";
    cin >> n;
    cout << "Enter number of queries: ";
    cin >> q;
    
    vvi queries(q, vi(3));
    cout << "Enter queries (a b k):" << endl;
    for(int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
    }
    
    cout << arrayManipulation(n, queries) ;
}