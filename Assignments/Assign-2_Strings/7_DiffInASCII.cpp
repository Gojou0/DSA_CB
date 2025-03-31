#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    cin >> s;
    string ans;
    for (int i = 1; i < s.size(); i++){
        int a = s[i] - s[i-1];
        ans += s[i-1] + to_string(a);
    }
    int n = s.size();
    ans += s[n-1];
    cout << ans << endl;
}