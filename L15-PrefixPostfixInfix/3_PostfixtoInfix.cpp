// Add operands in stack and pop whenever operator encounters
#include<iostream>
#include<stack>
#include<string>
using namespace std;

string PotoIn(string s){
    stack<string> st;
    int i = 0;
    while (i < s.size()){
        if (isalnum(s[i])){
            string sd = string("") + s[i];
            st.push(sd);
        }else{
            string s2 = st.top();                   // first top as s2... bcoz of forward traversal pushing
            st.pop();
            string s1 = st.top();
            st.pop();
            string ns = '(' + s1 + s[i] + s2 + ')';         // use close brackets to enclose an expression
            st.push(ns);
        }
        i++;
    }
    return st.top();
}

int main(){
    string s;
    cin >> s;
    string ans = PotoIn(s);
    cout << ans << endl;
}