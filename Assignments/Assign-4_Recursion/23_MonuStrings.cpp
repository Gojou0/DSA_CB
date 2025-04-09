#include<iostream>
#include<string>
using namespace std;

void Solve(string &s, string &ans, string &temp, int i = 0){
    if (i == s.size()){
        if (temp < ans){
            ans = temp;
        }
        return;
    }

    for (int j = i; j < s.size(); j++){
        if ( j > i && s[j] == s[j-1]) continue;
        temp += s[j];
        Solve(s, ans, temp, j+1);
        temp.pop_back();
    }
}

int main(){
    string s;
    cin >> s;
    string ans = s;
    string temp;
    Solve(s, ans, temp);
    cout << ans << endl;
}