#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int inx = 0;
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] != val){
                nums[inx] = nums[i];
                inx++;
            }
        }
        return inx;
    }
};
void main() {
    Solution sol;
    int n, val;
    cout <<"Enter Size: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter elements of vector: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "enter value to remove: ";
    cin >> val;
    int newSize = sol.removeElement(nums, val);
    cout << "Updated vector: ";
    for(int i = 0; i < newSize; i++) {
        cout << nums[i] << " ";
    }
}
