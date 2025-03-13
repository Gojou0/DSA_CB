#include <iostream>
using namespace std;

int main(){
    int sum;
    int a[] = {1,2,3,4,5};
    int n = sizeof(a)/sizeof(int);
    int si,sj;
    int ans = INT_MIN;
    int ps[100] = {0};

    // find prefix sum first
    ps[0] = a[0];
    for(int i = 1; i < n; i++){
        ps[i] = ps[i-1] + a[i];
    }

    //MAX sum Algo 
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            sum = ps[j] - (i-1 >= 0 ? ps[i-1] : 0);
            if (sum > ans){
                ans = sum;
                si = i;
                sj = j;
            }
        }
    }
    cout << ans << endl;
    for (int i = si; i <= sj ; i++){
        cout << a[i];
    }
    return 0;
}