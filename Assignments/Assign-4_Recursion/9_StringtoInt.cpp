#include<iostream>
using namespace std;

int StringtoInt(string &s, int n){
    if (n == 0) return 0;

    return (s[n-1] - '0') + (StringtoInt(s, n-1) *10);
}

int main(){
    string s;
    cin >> s;
    
    int n = s.size();
    cout << StringtoInt(s, n) << endl;
}