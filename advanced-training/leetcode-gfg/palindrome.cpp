// User function Template for C++
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool isPalindrome(int n) {
        int i=0,newNum=0,givenNum=n;
        while(givenNum){
            int curr = givenNum%10;
            newNum = newNum*10 + curr;
            givenNum = (givenNum-curr)/10;
        }
        return newNum==n?true:false;
    }
};

void main() {
    Solution sol;
    int n;
    cin >> n;
    cout << (sol.isPalindrome(n) ? "true" : "false");
}