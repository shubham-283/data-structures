#include<bits/stdc++.h>
using namespace std;
bool binarySearch(vector<int> &nums, int search) {
    int low = 0;
    int high = nums.size() - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(nums[mid] == search) {
            return true;
        }
        if(nums[mid] < search) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}


int binarySearch2(vector<int> &nums,int search,int low,int high){
    int mid = low + (high - low) / 2;
    if(search == nums[mid]){
        return mid;
    }
    if(low > high){
        return -1;
    }
    if(nums[mid] < search){
        return binarySearch2(nums,search,mid+1,high);
    }
    else
        return binarySearch2(nums,search,low,mid-1);
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int search;
    cin >> search;
    bool result = binarySearch(nums, search);
    if(result) {
        cout << "Element found" << endl;
    } else {
        cout << "Element not found" << endl;
    }
    return 0;
}

//upper bound > x     -- O(log n)
//lower bound >= x    -- O(log n)
//binary search       -- O(log n)