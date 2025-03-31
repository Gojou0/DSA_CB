#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int ans[n];
    int l = 0, r = n - 1;
    int i = n - 1;
    while (l <= r){
        int lsq = a[l] * a[l];
        int rsq = a[r] * a[r];

        if (lsq < rsq){
            ans[i] = rsq;
            r--;
        }else{
            ans[i] = lsq;
            l++;
        }
        i--;
    }
    for (int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
}
