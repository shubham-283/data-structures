#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int min = prices[0];
        int max = 0;


        for (int i=1; i<prices.size(); i++) {
            int curr = prices[i]-min;
            if (curr > max) 
                max=curr;

            if (prices[i] < min)
                min=prices[i];
        }

        return max;
    }
};
void main() {
    Solution sol;
    int n;
    cout << "Enter Size: ";
    cin >> n;
    vector<int> prices(n);
    
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    
    cout << sol.maxProfit(prices); 
}