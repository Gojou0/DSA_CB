#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

// B.P -> Saari digits k liye combo bnane
// C.P -> pehli k alawa baki k bnwalo
// Work -> pehle digit k liye combo bnao
int c = 0;

void KeypadSolve(map<int, vector<char> > &keypad, string digit, string &ans, int i = 0){
    // Base case
    if (i == digit.size()){
        cout << ans << endl;
        c++;
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
    map<int, vector<char>> keypad = {
    {1, {'a', 'b', 'c'}}, {2, {'d', 'e', 'f'}},
    {3, {'g', 'h', 'i'}}, {4, {'j', 'k', 'l'}},
    {5, {'m', 'n', 'o'}}, {6, {'p', 'q', 'r', 's'}},
    {7, {'t', 'u', 'v'}}, {8, {'w', 'x'}}, {9, {'y', 'z' }}
    };
     
    string digit;
    cin >> digit;

    string ans;
    KeypadSolve(keypad, digit, ans);
    cout << c << endl;
}