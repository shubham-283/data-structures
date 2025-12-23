#include<bits/stdc++.h>

using namespace std;

string postfix(string infix){
    unordered_map<char, int> priority = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}};
    string post;
    stack<char> st;

    for(char &ch : infix){
        if(isalnum(ch)){
            post += ch;
        }
        else if(ch == '('){
            st.push(ch);
        }
        else if(ch == ')'){
            while(st.top()!='('){
                post += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && (priority[ch] <= priority[st.top()])){
                post += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while(!st.empty()){
        post += st.top();
        st.pop();
    }
    return post;
}
int main(){
    string  str= "a+b*(c^d-e)^(f+g*h)-i";
    string ans = postfix(str);
    cout<< ans;
}