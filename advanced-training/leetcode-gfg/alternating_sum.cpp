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


    int alternateDigitSum(int n) {
        int sum=0;
        int reverseNum = reverseDigits(n);
        // printf("Number = %d\n",reverseNum);
        while(reverseNum){
            if(reverseNum){
                int val = reverseNum%10;
                sum = sum + val;
                reverseNum = reverseNum/10;
                // printf("Positive = %d\n",sum);
            }
            if(reverseNum){
                int val = reverseNum%10;
                sum = sum - val;
                reverseNum = reverseNum/10;
                // printf("Negative = %d\n",sum);
            }
        }
        return sum;
    }
};

void main() {
    Solution sol;
    int n;
    cin >> n;
    cout << sol.alternateDigitSum(n);
}