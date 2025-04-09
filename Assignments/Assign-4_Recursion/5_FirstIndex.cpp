#include<iostream>
using namespace std;

int First(int* arr, int n, int key){
    if (n == 0) return -1;

    if (arr[0] == key) return 0;
    return (First(arr+1, n-1, key) >= 0) ? First(arr+1, n-1, key) + 1 : -1;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int key;
    cin >> key;

    cout << First(arr, n, key) << endl;
}