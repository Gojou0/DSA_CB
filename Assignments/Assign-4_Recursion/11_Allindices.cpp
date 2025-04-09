#include<iostream>
using namespace std;

void All(int* arr, int n, int i, int key){
    if (i == n) return;

    if (arr[i] == key) cout << i << " ";
    All(arr, n, i+1, key);
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

    All(arr, n, 0, key);
}