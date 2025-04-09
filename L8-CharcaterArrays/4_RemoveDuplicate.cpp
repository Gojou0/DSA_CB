#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    string s;
    cin >> s;

    int i = 0; 
    int j = 1;
    while (j < s.size()){
        if (s[i] != s[j]){
            i++;
            s[i] = s[j];
        }
        j++;
    }

    for (int k = 0; k <= i; k++){
        cout << s[k];
    }
}