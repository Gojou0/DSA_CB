#include<iostream>
using namespace std;

int main(){
    int a[] = {4,5,0,-2,-3,1};
    int k = 5;
    int n = sizeof(a) / sizeof(int);

    // HASH Approach

    // unordered_map <int> mp;
    // mp[0] = 1;
    // int sum = 0;
    // int ans = 0;
    // for (int i = 0; i < n; i++){
    //     sum += a[i];
    //     int mod = sum % k;
    //     if (mod < 0){
    //         mod += k;
    //     }
    //     if (mp.find(mod) != mp.end()){
    //         ans += mp[mod];
    //     }
    //     mp[mod]++;
    // }

    // cout << ans << endl;

    // Second Approach

    int ps[100] = {0};
    ps[0] = a[0];
    for (int i = 1; i < n; i++){
        ps[i] = ps[i - 1] + a[i];
    }
    for (int i = 0; i < n; i++){
        ps[i] = ps[i] % k;
        if (ps[i] < 0) {
            ps[i] += k;
        }
    }

    int modcnt[100] = {1};              // as empty subarray has 0 mod and therfore count is 1;
    int ans = 0;
    for (int i = 0; i < n; i++){
        modcnt[ps[i]]++;
    }

    //nc2 = n * (n-1) / 2           // to find subarray
    for (int i = 0; i < k; i++){
        ans += modcnt[i] * (modcnt[i] - 1) / 2;
    }

    cout << ans << endl;

    return 0;
}