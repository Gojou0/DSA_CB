#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;

    int ans = 0;
    for (int i = 1; i < n-1; i++){
        if (s2[i] == '.' && s2[i-1] == 'x' && s2[i+1] == 'x') ans++;
        if (s1[i] == '.' && s1[i-1] == 'x' && s1[i+1] == 'x') ans++;
    }

    cout << ans << endl;
    return 0;

}