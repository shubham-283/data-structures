#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum=0;
        int i=0;

        for(int j=0;j<chalk.size();j++){
                sum = sum+chalk[j];
        }

        int newk = k%sum;
        int newSum=0;
        for(i=0;i<chalk.size();i++){
            newSum = newSum + chalk[i];
            if(newSum >newk)
                return i;
        }
        return i;
    }
};
void main() {
    Solution sol;
    int n;
    cout << "Enter Size Of Vector: ";
    cin >> n;
    vector<int> chalk(n);
    cout << "Enter Elements Of Vector: ";
    for(int i=0;i<n;i++){
        cin >> chalk[i];
    }
    cout << "Enter Value Of k: ";
    long long k;
    cin >> k;
    cout << sol.chalkReplacer(chalk, k); 
}