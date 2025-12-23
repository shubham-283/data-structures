#include<bits/stdc++.h>
using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int,int> m;
    for(int &index : arr){
        m[index]++;
    }
    set<int> s;
    for(auto &pair : m){
        if(s.count(pair.second))
            return false;
        else
            s.insert(pair.second);
    }
    return true;
    
}


void main() {
    int n;
    cout << "Enter Size: ";
    cin >> n;
    vector<int> nums(n);
    
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    cout << (uniqueOccurrences(nums) ? "true" : "false");
}
