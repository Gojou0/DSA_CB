#include<iostream>
using namespace std;

bool isSorted(int* a, int n, int i){
    if (i == n-1) return true;

    if (isSorted(a,n,i+1) && a[i] <= a[i+1]){
        return true;
    }else{
        return false;
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int arr[4];
    for (int i = 0; i < 4; i++){
        cin >> arr[i];
    }

    bool ans = isSorted(arr, 4, 0);

    cout << ans << endl;
}