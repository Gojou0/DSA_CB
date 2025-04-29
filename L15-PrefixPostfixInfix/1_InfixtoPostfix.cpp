// Operators having strictly greator priority gets added to stack
#include<iostream>
#include<stack>
#include<unordered_map>
using namespace std;

string IntoPo(string s){
    int i  = 0;
    stack<char> st;
    string ans;
    unordered_map<char, int> mp;
    mp['+'] = 1;
    mp['-'] = 1;
    mp['*'] = 2;
    mp['/'] = 2;
    mp['^'] = 3;
    while (i < s.size()){
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            ans += s[i];
        }else if (s[i] == '('){
            st.push(s[i]);
        }else if (s[i] == ')'){
            while (!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        }else{
            while (!st.empty() && mp[s[i]] <= mp[st.top()]){
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while (!st.empty()){
        ans += st.top();
        st.pop();
    }

    return ans;
}

int main(){
    string s;
    cin >> s;
    string ans = IntoPo(s);
    cout << ans << endl;
}