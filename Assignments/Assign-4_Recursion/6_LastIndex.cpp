#include<iostream>
using namespace std;

int Last(int* arr, int n, int key){
    if (n == 0) return -1;

    if (arr[n-1] == key) return n-1;
    return (Last(arr, n-1, key) >= 0) ? Last(arr, n-1, key) : -1;
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

    cout << Last(arr, n, key) << endl;
}