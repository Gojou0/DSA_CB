#include<iostream>
#include<string>
#include<vector>
using namespace std;

int Twins(string s, int i = 0){
    if (i+2 == s.size()){
        return 0;
    }

    int cnt = 0;
    if (s[i] == s[i+2] && s[i] != s[i+1]){
        cnt = 1;
    }
    
    return cnt + Twins(s, i+1);
}

int main(){
    string s;
    cin >> s;
    cout << Twins(s) << endl;
}