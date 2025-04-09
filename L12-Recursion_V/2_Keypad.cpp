#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<bits/stdc++.h>
using namespace std;

// B.P -> Saari digits k liye combo bnane
// C.P -> pehli k alawa baki k bnwalo
// Work -> pehle digit k liye combo bnao

void KeypadSolve(map<int, vector<char> > &keypad, string digit, string &ans, int i = 0){
    // Base case
    if (i == digit.size()){
        cout << ans << endl;
        return;
    }

    // Recursive case
    int dig = digit[i] - '0';
    for (char x : keypad[dig]){
        ans += x;
        KeypadSolve(keypad, digit, ans, i+1);
        ans.pop_back();
    }
}

int main(){
    map<int, vector<char> > keypad = {
        {2, {'A', 'B', 'C'}}, {3, {'D', 'E', 'F'}}, {4, {'G', 'H', 'I'}}, 
        {5, {'J', 'K', 'L'}}, {6, {'M', 'N', 'O'}}, {7, {'P', 'Q', 'R', 'S'}}, 
        {8, {'T', 'U', 'V'}}, {9, {'W', 'X', 'Y', 'Z'}}
    };
    
    string digit;
    cin >> digit;

    string ans;
    KeypadSolve(keypad, digit, ans);
}