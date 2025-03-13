// On Leetcode
#include <iostream>
using namespace std;

int main(){
    int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = sizeof(a) / sizeof(int);
    int left[100] = {0};
    int right[100] = {0};

    left[0] = 0;
    for (int i = 1; i < n; i++){
        left[i] = max(a[i-1],left[i-1]);
    }

    right[n-1] = 0;
    for (int i = n-2; i >= 0; i--){
        right[i] = max(right[i+1],a[i+1]);
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++){
        int res = min(left[i], right[i]) - a[i];
        ans += (res > 0 ? res : 0);
    }
    cout << "water is trapped : " << ans << endl;
}