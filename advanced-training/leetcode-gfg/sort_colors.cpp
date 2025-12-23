#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n0=0,n1=0,n2=0,i=0;
        while(i<nums.size()){
            if(nums[i] == 0)
                n0++;
            else if(nums[i] == 1)
                n1++;
            else 
                n2++;
            i++;
        }
        i=0;
        while(n0){
            nums[i] = 0;
            i++;
            n0--;
        }
        while(n1){
            nums[i] = 1;
            i++;
            n1--;
        }
        while(n2){
            nums[i] = 2;
            i++;
            n2--;
        }
    }
};

int main() {
    Solution sol;
    int n;
    cin >> n;
    vector<int> nums(n);
    
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    
    sol.sortColors(nums);
    
    for(auto &val : nums){
        cout << val << " ";
    }
    
    return 0;
}