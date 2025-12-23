#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int vectorSize = nums.size();
        for(int i=0;i<vectorSize-1;i++){
            for(int j=i+1;j<vectorSize;j++){
                if(nums[i]+nums[j] == target)
                    return {i,j};
            }
        }
        return{0,0};
    }
};

void main() {
    Solution sol;
    int n, target;
    cout << "Enter Size: ";
    cin >> n;
    vector<int> nums(n);
    
    cout << "Enter elements of vector: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    cout << "Target: ";
    cin >> target;
    
    vector<int> result = sol.twoSum(nums, target);
    
    cout <<"Indices are: " <<result[0] << ", " << result[1];
}