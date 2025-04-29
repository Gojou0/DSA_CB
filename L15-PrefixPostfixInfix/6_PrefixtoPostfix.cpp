// Add operands in stack and pop whenever operator encounters
#include<iostream>
#include<string>
#include<stack>
using namespace std;

string PretoPo(string s){
    stack<string> st;
    int i = s.size() - 1;
    while (i >= 0){
        if (isalnum(s[i])){
            string sd = string("") + s[i];
            st.push(sd);
        }else{
            string s1 = st.top();
            st.pop();
            string s2 = st.top();
            st.pop();
            string ns = s1 + s2 + s[i];             // operands and then operator
            st.push(ns);
        }
        i--;
    }
    return st.top();
}

int main(){
    string s;
    cin >> s;
    string ans = PretoPo(s);
    cout << ans << endl;
}