#include<iostream>
using namespace std;

int main(){
    int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = sizeof(arr) / sizeof(int);

    int lmax = 0, rmax = 0, total = 0;
    int l = 0;
    int r = n-1;

    while (l < r){
        if (arr[l] <= arr[r]){                  // work only with smaller one
            if (lmax >= arr[l]){
                total += lmax - arr[l];             // total gets added if lmax or rmax is greater
            }else{
                lmax = arr[l];
            }
            l++;
        }else{
            if (rmax >= arr[r]){
                total += rmax - arr[r];
            }else{
                rmax = arr[r];
            }
            r--;
        }
    }

    cout << "Water is trapped : " << total;
    
}