#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    long long res[n];
    long long ans = 1;
    for (int i = 0; i < n; i++){
        res[i] = ans;
        ans *= a[i]; 
    }
    ans = 1;
    for (int i = n - 1; i >= 0; i--){
        res[i] = res[i] * ans;
        ans *= a[i];
    }
    for (int i = 0; i < n; i++){
        cout << res[i] << " ";
    }
    return 0;
}