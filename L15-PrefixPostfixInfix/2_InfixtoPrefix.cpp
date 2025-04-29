// Operators having greator or equal priority gets added to stack except for power(^) operator
#include<iostream>
#include<stack>
#include<unordered_map>
using namespace std;

string IntoPre(string s){
    reverse(s.begin(), s.end());
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
            if (s[i] == '^'){
                while (!st.empty() && mp[s[i]] <= mp[st.top()]){
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }else{
                while (!st.empty() && mp[s[i]] < mp[st.top()]){
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        i++;
    }
    while (!st.empty()){
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    string s;
    cin >> s;
    string ans = IntoPre(s);
    cout << ans << endl;
}