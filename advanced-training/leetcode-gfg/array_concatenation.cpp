#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans(2*nums.size());
        
        for(int i=0;i<nums.size();i++){
            ans[i + nums.size()] = ans[i] =nums[i];
        }
        return ans;
    }
};

void main() {
    Solution sol;
    int n;
    cin >> n;
    vector<int> nums(n);
    
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    
    vector<int> ans = sol.getConcatenation(nums);
    
    for(auto &val : ans){
        cout << val << " ";
    }
}   