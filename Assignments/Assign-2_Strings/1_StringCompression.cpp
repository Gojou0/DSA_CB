#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    cin >> s;
    string ans;
    int n = s.size();
    int c = 1;
    
    for (int i = 1; i < n; i++){
        if (s[i] == s[i-1]){
            c++;
        }else{
            ans += s[i-1] + to_string(c);
            c = 1;
        }
    }
    ans += s[n-1] + to_string(c);
    cout << ans << endl;
}