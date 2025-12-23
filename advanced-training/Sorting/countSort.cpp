#include<bits/stdc++.h>
using namespace std; 

void countSort(vector<int>& nums) {
    if (nums.empty()) return;

    int minVal = *min_element(nums.begin(), nums.end());
    int maxVal = *max_element(nums.begin(), nums.end());

    vector<int> count(maxVal - minVal + 1, 0);

    for (int num : nums) {
        count[num - minVal]++;
    }

    int index = 0;
    for (int i = 0; i < count.size(); i++) {
        while (count[i] > 0) {
            nums[index++] = i + minVal;
            count[i]--;
        }
    }
}

int main() {
    vector<int> nums = {-1, 0, 3, 3, 1};
    countSort(nums);
    
    cout << "Sorted array: ";
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}