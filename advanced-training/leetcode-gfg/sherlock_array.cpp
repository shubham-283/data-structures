#include<bits/stdc++.h>
using namespace std;

bool balancedSums(vector<int> arr) {
    int i=0;
    int j=arr.size()-1;
    int left_sum = arr[i];
    int right_sum =arr[j];
    while(i<j){
        if(left_sum < right_sum){
            // printf("left\n");
            // i++;
            left_sum += arr[++i];
        }
        else{
            // printf("right\n");
            // j--;
            right_sum += arr[--j];
        } 
    }
    return (left_sum - right_sum == 0)? true : false;
}

void main() {
    int n;
    cout << "Enter Size: ";
    cin >> n;
    vector<int> arr(n);
    
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << (balancedSums(arr) ? "YES" : "NO");
}