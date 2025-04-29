// Add operands in stack and pop whenever operator encounters
#include<iostream>
#include<stack>
#include<string>
using namespace std;

string PotoPre(string s){
    stack<string> st;
    int i = 0;
    while (i < s.size()){
        if (isalnum(s[i])){
            string sd = string("") + s[i];
            st.push(sd);
        }else{
            string s2 = st.top();
            st.pop();
            string s1 = st.top();
            st.pop();
            string ns = s[i] + s1 + s2;             // operator and then operands
            st.push(ns);
        }
        i++;
    }
    return st.top();
}

int main(){
    string s;
    cin >> s;
    string ans = PotoPre(s);
    cout << ans << endl;
}