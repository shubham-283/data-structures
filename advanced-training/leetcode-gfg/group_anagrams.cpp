#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
typedef vector<vector<string>> vvs;
typedef unordered_map<string,vector<string>> usvs;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vvs res;
        usvs groups;

        for(const string &s : strs){

                /*
                //example s = aabacaababaaad
                //to_string and concatenation method is slower
                
                vector<int> count(26,0);
                
                for(int i=0 ; i<s.length();i++){
                    count[s[i]-'a']++;
                }
                
                
                string key = to_string(count[0]);
                for(int i=1;i<26;i++){
                    key += "|"+to_string(count[i]);
                }
                
                //here key will be of 26 digits + 25 pipes(|) like -> 9|3|1|1|0|0|0|0|0|...
                //pipe symbol is required to differentiate between 11 and 1 or 1 and 11
                */
            
            
            string key(26,0);
            for(char ch : s){
                key[ch-'a']++;
            }
            //here key will be of 26 digits and ascii character(ie 1 and 11 will be different in each case) at each place like -> 9 3 1 1 0 0 0 0 0...
            
            
            groups[key].push_back(s);
        }
        for(const pair<string,vector<string>> pr: groups){
            res.push_back(pr.second);
        }
        return res;
    }


    //second approach - making key by sorting the string 
    vector<vector<string>> groupAnagrams2(vector<string>& strs) {
        usvs mp;

        for(string &s: strs){
            string temp =s;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(s);
        }

        vector<vector<string>> ans;
        for(pair<const string, vector<string>> &s:mp){
            ans.push_back(s.second);
        }
        return ans;
    }


};

void printResult(vector<vector<string>>& result) {
    cout << "{" << endl;
    for (auto& group : result) {
        cout << "  [";
        for (int i = 0; i < group.size(); i++) {
            cout << "\"" << group[i] << "\"" << (i == group.size() - 1 ? "" : ", ");
        }
        cout << "]" << endl;
    }
    cout << "}" << endl;
}

int main() {
    Solution sol;

    vector<string> test1 = {"", "a", "", "b", "a"};
    vector<string> test2 = {"aaab", "aabb", "baaa", "abab", "baba"};
    vector<string> test3 = {"aaaaaaaaaa", "aaaaaaaaaa", "aaaaaaaaab"};
    vector<string> test4 = {"abc", "def", "ghi", "jkl"};
    cout << "Test 1 Results:" << endl;
    auto res1 = sol.groupAnagrams(test1);
    printResult(res1);
    cout << "\nTest 2 Results:" << endl;
    auto res2 = sol.groupAnagrams(test2);
    printResult(res2);

}