#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &nums){
    for(int i=0;i<nums.size();i++){
        for(int j=0;j<nums.size()-i-1;j++){
            if(nums[j] > nums[j+1]){
                swap(nums[j],nums[j+1]);
            }
        }
    }
}


void selectionSort(vector<int> &nums){
    for(int i=0;i<nums.size();i++){
        int min = i;
        for(int j=i+1;j<nums.size();j++){
            if(nums[j] < nums[min])
                min = j;
        }
        swap(nums[min],nums[i]);
    }
}



void insertionSort(vector<int> &nums){
    for(int i=1;i<nums.size();i++){
        int curr = nums[i];
        int j= i-1;
        while(j >= 0 && nums[j] > curr){
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = curr;
    }
}



void insertion(vector<int> &nums){
    for(int i=1;i<nums.size();i++){
        int curr = nums[i],j;
        for(j=i-1;j>=0;j--){
            if(nums[j] > curr)
                nums[j+1] = nums[j];
            else
                break;
        }
        nums[j+1] = curr;
    }
}

void insertion2(vector<int> &nums){
    for(int i=1;i<nums.size();i++){
        for(int j=i;j>=1&& nums[j] < nums[j-1];j--){
            swap(nums[j],nums[j-1]);
        }
    }
}


int main() {
    vector<int> nums = {64, 34, 25, 12, 22, 11, 90};
    insertionSort(nums);
    for (int &i : nums) {
        cout << i << " ";
    }
    return 0;
}