#include<bits/stdc++.h>
using namespace std;
vector<int> replaceElements(vector<int>& arr) {
    int max=0;
    int curr =0;
    int n = arr.size();
    if (n==1){
        return {-1};
    }
    int index = arr[n-1];
    for(int i = n-2;i>=0;i--){
        int curr = arr[i];
        arr[i] = index;
        if(index < curr){
            index = curr;
        }
    }
    arr[n-1] =-1;
    return arr;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<int> result = replaceElements(arr);
    for(int i = 0; i < n; i++){
        cout << result[i] << " ";
    }
}