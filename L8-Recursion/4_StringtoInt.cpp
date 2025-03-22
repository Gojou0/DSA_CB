#include <iostream>
using namespace std;

int StringtoInt(char *ch, int n){
    if (ch[0] == '\0') return 0;

    return (ch[0] - '0') * pow(10, n) + StringtoInt(ch+1, n - 1);
}

// int StringtoInt(char *ch, int n){
//     if (n == 0) return 0;
//     return (ch[n-1] - '0') + StringtoInt(ch, n-1) * 10;
// }

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    char ch[10] = "1234";
    int n = StringtoInt(ch, strlen(ch) - 1);
    cout << n << endl;
}