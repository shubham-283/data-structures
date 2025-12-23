#include <iostream>
using namespace std;
class Solution {
  public:
    bool armstrongNumber(int n) {
        // code here
        int cpnum =n;
        int sum =0;
        while(cpnum){
            int val = cpnum%10;
            sum = sum + (val*val*val);
            cpnum = cpnum/10;
        }
        return sum == n ? true : false;
    }
};
void main() {
    Solution sol;
    int n;
    cin >> n;
    cout << (sol.armstrongNumber(n) ? "true" : "false");
}