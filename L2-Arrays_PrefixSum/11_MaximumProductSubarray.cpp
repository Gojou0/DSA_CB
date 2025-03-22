#include<iostream>
using namespace std;
int main(){
    int a[4] = {2,3,-2,4};
    int n = 4;
    int prefix = 1;
    int suffix = 1;
    int ans =INT_MIN;
    for (int i = 0; i < n; i++){
        if (prefix == 0) prefix = 1;                // if prefix  or suffix gets 0 by multiplication of 0 then change it to 1
        if (suffix == 0) suffix = 1;
        
        prefix *= a[i];
        suffix *= a[n-i-1];
        ans =max(ans, max(prefix, suffix));         
    }
    cout << ans << endl;
}
