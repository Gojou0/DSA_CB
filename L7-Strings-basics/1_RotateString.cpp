#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    string s;
    cin >> s;
    int n = s.size();
    int k;
    cin >> k;
    reverse(s.begin(), s.begin()+n-k);
    reverse(s.begin()+n-k, s.end());
    reverse(s.begin(),s.end());
    cout << s << endl;
}