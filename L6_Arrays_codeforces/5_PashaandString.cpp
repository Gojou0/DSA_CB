#include <iostream>
using namespace std;

int cnt[100005] = {0};

int main(){

    string s;
    cin >> s;
    int n = s.size();
    int m;
    cin >> m;
    int ai;
    for (int i = 0; i < m; i++){
        cin >> ai;
        cnt[ai - 1]++;                  // konse index swap honge wo cnt array me le liye 
    }
    // for (int i = 0; i < m; i++){
    //     reverse(s.begin() + (positions[i] - 1), s.begin() + (n - positions[i]));
    // }

    // cout << s << endl;

    for (int i = 1 ; i < n / 2; i++){
        cnt[i] += cnt[i - 1];               // no. of swaps ka prefix sum bna lia
    }

    for (int i = 0; i < n / 2; i++){
        if (cnt[i] % 2 != 0){                   // agr even br swap hua mtlb no change and vice versa
            swap(s[i], s[n - i - 1]);
        }
    }

    cout << s << endl;
}