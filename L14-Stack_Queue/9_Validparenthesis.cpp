#include<iostream>
#include<stack>
using namespace std;

bool Solve(string s){
    stack<int> st;

    for (int i = 0; i < s.size(); i++){
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
        else{
            if (st.empty()) return false;
            char ch = st.top();
            st.pop();                   // pop to check next element in next iteration
            if (ch == '(' && s[i] == ')') continue;
            else if (ch == '[' && s[i] == ']') continue;
            else if (ch == '{' && s[i] == '}') continue;
            else return false;
        }
    }
    return st.empty();          // agr pura khali ho jaye ...tbhi valid hogye saare parenthesis
}

int main(){
    string s;
    cin >> s;

    bool ans = Solve(s);
    cout << ans << endl;
}
    