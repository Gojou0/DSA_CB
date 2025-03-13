#include<iostream>
using namespace std;

void PrintPermuatation(int index, int arr[], int n){
    if (index == n){                    //base condition
        for (int i = 0; i < n; i++){
            cout << arr[i];
        }
        cout << endl;
    }else{
        for (int i = index; i < n; i++){
            swap(arr[index],arr[i]);            //swap to get permutation
            PrintPermuatation(index + 1, arr, n);               //call fn recursively for each index
            swap(arr[index],arr[i]);            //swap back to get og arr for next iteration
        }
    }
}

int main(){
    int a[] = {1,2,3};
    int n = sizeof(a) / sizeof(int);
    PrintPermuatation(0, a, n);
}