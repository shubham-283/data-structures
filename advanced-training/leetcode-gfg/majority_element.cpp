#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
    int max =0;
    unordered_map<int,int> m;
    for(int &index : nums){
        m[index]++;
        if(m[index] > m[max] && index!=max  )
            max = index;
    }
    return max;
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
    
    cout << majorityElement(nums);
}