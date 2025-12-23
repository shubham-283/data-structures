#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int index=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i] != 0){
            nums[index++] = nums[i];
        }
    }
    while(index < nums.size())
        nums[index++] = 0;
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
    
    moveZeroes(nums);
    
    cout << "Output: ";
    for(int num : nums) {
        cout << num << " ";
    }
}