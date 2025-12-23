#incluse<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastSeen(128,-1);
        int maxLength = 0;
        int i =0;

        for(int j = 0;j<s.size();j++){
            char ch = s[j];


            if(lastSeen[ch] >= i)
                i = lastSeen[ch] + 1;

            lastSeen[ch] = j;
            maxLength = max(maxLength, j-i+1);
        }


        return maxLength;
    }
};



int main() {
    Solution sol;
    string case1 = "bbbbb";
    cout << "Test 1 (bbbbb): " << sol.lengthOfLongestSubstring(case1) << endl;

    string case2 = "abcdefg";
    cout << "Test 2 (abcdefg): " << sol.lengthOfLongestSubstring(case2) << endl;

    string case3 = "pwwkew";
    cout << "Test 3 (pwwkew): " << sol.lengthOfLongestSubstring(case3) << endl;

    string case4 = "abba";
    cout << "Test 4 (abba): " << sol.lengthOfLongestSubstring(case4) << endl;

    string case5 = "";
    cout << "Test 5 (Empty): " << sol.lengthOfLongestSubstring(case5) << endl;

    string case6 = "a b c a ";
    cout << "Test 6 (a b c a ): " << sol.lengthOfLongestSubstring(case6) << endl;

}