#include<bits/stdc++.h>
using namespace std;

vector<int> runningSum(vector<int>& nums) {
    for(int i =1; i<nums.size();i++){
        nums[i] = nums[i]+nums[i-1];
    }
    return nums;
}


void main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> result = runningSum(nums);
    for(int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
}