#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count =0;
        for(int i=0;i<nums.size();i++){
            int j = nums.size()-1;
            while(i<j){
                if(nums[i] == nums[j]){
                    count++;
                }
                j--;
            }
        }
        return count;
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
    cout << sol.numIdenticalPairs(nums); 
}