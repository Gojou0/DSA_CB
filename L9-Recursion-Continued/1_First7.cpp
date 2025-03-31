#include <iostream>
using namespace std;

int First7(int* arr, int n, int a){
    if (n == 0) return -1;             // n is number of elements not index 
    if (arr[0] == a) return 0;
    return (First7(arr+1, n-1, a) != -1) ? First7(arr+1, n-1, a) + 1 : -1;
}

int Lastn(int* arr, int n, int a){
    if (n == 0) return -1;              // n is number of elements not index
    if (arr[n-1] == a) return n-1;
    return (Lastn(arr, n-1, a) != -1) ? Lastn(arr, n-1, a) : -1;
}

void All7(int* arr, int i, int n, int a){
    if (i >= n) return;                 // here n is index ...and we use iterative appraoch
    if (arr[i] == a) cout << i << " ";
    All7(arr, i+1, n, a);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    int a[10005];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << First7(a, n, 7) << endl;
    cout << Lastn(a, n, 7) << endl; 
    All7(a, 0, n, 7);
}