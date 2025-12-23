#include <iostream>
using namespace std;
class Solution {
  public:
    int reverseDigits(int n) {
        int i=0,newNum=0;
        while(n){
            int curr = n%10;
            newNum = newNum*10 + curr;
            n = n/10;
        }
        return newNum;
    }
};
void main() {
    Solution sol;
    int n;
    cin >> n;
    cout << sol.reverseDigits(n);
}