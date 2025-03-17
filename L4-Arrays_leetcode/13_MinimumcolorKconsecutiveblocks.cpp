// on leetcode
#include <iostream>
#include<algorithm>
using namespace std;

int main(){
    string a = "WBBWWBBWBW";
    int n = a.size();
    int k = 7;
    int c = 0;
    for (int i = 0; i < k; i++){
        if (a[i] == 'W'){
            c++;
        }
    }
    int ans = c;
    for (int i = k; i < n; i++){
        if (a[i - k] == 'W') c--;
        if (a[i] == 'W') c++;
        ans = min(ans,c);
    }
    cout << ans << endl;
}