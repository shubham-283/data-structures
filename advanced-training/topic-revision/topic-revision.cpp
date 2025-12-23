#include<bits/stdc++.h>

using namespace std;



int buySellStock(vector<int> &prices){
    int minPrice = INT_MAX;
    int maxProfit = 0;
    for(int price : prices){
        if(price < minPrice)
            minPrice = price;
        else if(price-minPrice > maxProfit)
            maxProfit = price-minPrice;
    }
    return maxProfit;
}

int maxArea(vector<int>& height){
    int left = 0;
    int right = height.size()-1;
    
    // int length = min(height[left],height[right]);
    int maxArea = INT_MIN;
    
    while(left<right){
        int breadth = right-left;
        int length = min(height[left],height[right]);
        int currArea = length * breadth;
        maxArea = max(maxArea,currArea);
        if(height[left]<height[right])
            left++;
        else
            right--;
    }
    return maxArea;
}


int lengthOfLongestSubstring(string s){
    if(s=="") return 0;
    vector<int> seen(128,-1);
    
    int start=0;
    int longest = INT_MIN;
    
    for(int end=0;end<s.length();end++){
        char curr = s[end];
        
        if(seen[curr] >= start){
            start = seen[curr]+1;
        }
        seen[curr] = end;
        
        longest = max(longest, end - start + 1);
    }
    return longest;
}


int main(){
    // vector<int> prices = {3, 10, 1, 5};
    // cout<<buySellStock(prices);
    
    
    
    // vector<int> heights = {1, 2, 1, 1, 1, 1, 2, 1};
    // cout<<maxArea(heights);
    
    
    string s="au";
    cout<<lengthOfLongestSubstring(s);
    
    
}