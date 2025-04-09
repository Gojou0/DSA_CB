#include<iostream>
using namespace std;

int c = 0;

void Subsequence(string s, string temp, int i, int j){
    if (i == s.size()){
        cout << temp << " ";
        c++;
        return;
    }

    Subsequence(s, temp, i+1, j);
    temp += s[i];
    Subsequence(s, temp, i+1, j+1);
}

int main(){
    string s;
    cin >> s;
    string temp;

    Subsequence(s, temp, 0, 0);
    cout << endl;
    cout << c << endl;
}