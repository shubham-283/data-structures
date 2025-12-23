#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int smallestEvenMultiple(int n) {
        return n%2 ? n*2: n;
    }
};
void main() {
    Solution sol;
    int n;
    cout <<"Enter a number: ";
    cin>> n;
    cout << sol.smallestEvenMultiple(n); 
}