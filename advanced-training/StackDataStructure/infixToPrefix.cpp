#include<bits/stdc++.h>

using namespace std;
//just 5 changes and infix to postfix will be converted to infix to prefix
string prefix(string infix){
    reverse(infix.begin(),infix.end());//1. first reverse the string
    unordered_map<char, int> priority = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}};
    string pre;
    stack<char> st;

    for(char ch : infix){
        if(isalnum(ch)){
            pre += ch;
        }
        else if(ch == ')'){//2. if compared to inf to post just interchange the brackets (<--->) because string is reversed
            st.push(ch);
        }
        else if(ch == '('){//3. if compared to inf to post just interchange the brackets (<--->) because string is reversed
            while(st.top()!=')'){//4. if compared to inf to post just interchange the brackets (<--->) because string is reversed
                pre += st.top();
                st.pop();
            }
            st.pop();
        }
        else{//most important part: check the priority of current operator if it is less than or equal to operator present at top pop every thing till condition matches
            while(!st.empty() && (priority[ch] <= priority[st.top()])){
                pre += st.top();
                st.pop();
            }
            st.push(ch);//dont forget to push current operator
        }
    }

    while(!st.empty()){
        pre += st.top();
        st.pop();
    }
    reverse(pre.begin(),pre.end());//5. finally reverse the answer
    return pre;
}
int main(){
    string  str= "(a-b/c)*(a/k-l)";
    string ans = prefix(str);
    cout<< ans;
}