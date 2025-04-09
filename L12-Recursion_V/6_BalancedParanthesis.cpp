#include<iostream>
#include<vector>
using namespace std;

// B.P -> Saare(2n) brackets ko add krna
// C.P -> 2n-1 brackets ko add krna
// Work -> ek bracket ko add krna

void Paranthesis(int n, string &ans, int i = 0, int j = 0){             // i -> opening brackets.....j->closing brackets
    if (i == n && j == n){
        cout << ans << endl;
        return;
    }

    if (i < n){
        ans += '(';
        Paranthesis(n, ans, i+1, j);
        ans.pop_back();
    }

    if (i > j){
        ans += ')';
        Paranthesis(n, ans, i, j+1);
        ans.pop_back();
    }
}

int main(){
    int n;
    cin >> n;
    string ans;
    Paranthesis(n, ans);
}