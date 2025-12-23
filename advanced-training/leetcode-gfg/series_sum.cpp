#include <iostream>
using namespace std;
class Solution {
  public:
    int seriesSum(int n) {
        // code here
        return n*(n+1)/2;
    }
};

void main() {
    Solution sol;
    int n;
    cin >> n;
    cout << sol.seriesSum(n);
}