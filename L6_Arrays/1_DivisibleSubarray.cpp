#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[] = {4,5,0,-2,-3,1};
    int k = 5;
    int n = sizeof(a) / sizeof(int);
    unordered_map <int> mp;
    mp[0] = 1;
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++){
        sum += a[i];
        int mod = sum % k;
        if (mod < 0){
            mod += k;
        }
        if (mp.find(mod) != mp.end()){
            ans += mp[mod];
        }
        mp[mod]++;
    }

    cout << ans << endl;

    return 0;
}