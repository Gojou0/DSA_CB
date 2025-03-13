// Buy stock and sell
#include <iostream>
using namespace std;

int main(){
    int a[] = {13,24,52,51,9};
    int n = sizeof(a) / sizeof(int);
    int suffix[100] = {0};

    //Create Suffix array for max element
    suffix[n-1] = a[n-1];
    for (int i = n-2; i >= 0; --i){
        suffix[i] = max(suffix[i+1],a[i]);
    }

    //Check Max Difference    // right side k max se hi minus kr skte bas ya fir left side ke minimum se
    int ans = INT_MIN;
    for (int i = 0; i < n ; ++i){
        ans = max(ans,suffix[i+1] - a[i]);
    }
    cout << "Max Difference : " << ans << endl;

    // int suffix = INT_MIN;
    // int ans = INT_MIN;
    // for(int i = n-1; i >= 0; i--){
    //     suffix = max(suffix,a[i]);
    //     ans = max(ans,suffix - a[i]);
    // }
    // cout<<ans<<" ";

    return 0;
}