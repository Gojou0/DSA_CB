#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    char a[100] = "Coding";
    char b[] = " Blocks";

    // int n = strlen(a);
    // int m = strlen(b);
    // int j = n;
    // for (int i = 0; i <= m; i++){
    //     a[j] = b[i];
    //     j++;
    // }

    strcat(a, b);
    cout << a << endl;
}