#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    cin.get();
    char a[100];
    string s;

    int ans = INT_MIN;
    for (int i = 0; i < n; i++){
        cin.getline(a, 100);
        int x = strlen(a);
        if (x >= ans){
            ans = x;
            s = a;
        }
    }
    cout << s << ans << endl;
}