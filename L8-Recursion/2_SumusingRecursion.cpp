#include<iostream>
using namespace std;

// int sumR(int a[], int n){
//     if (n == -1) {
//         return 0;
//     }
//     return a[n] + sumR(a, n-1);
// }

int sumR(int *a, int n){           // n is not index here....it is number of elements upto which sum is performed
    if (n == 0) return 0;

    return a[0] + sumR(a + 1, n - 1);       // a + 1 will now provide a[0] as a[1].....mtlb jidhar array point krta h udhr hi 0th index hota h
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << sumR(a, 3) << endl;
}