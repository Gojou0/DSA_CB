#include <iostream>
using namespace std;

int RotatedBsearch(int *a, int n, int key){
    int s = 0;
    int e = n - 1;
    while (s <= e){
        int mid = (s + e) / 2;
        if (key == a[mid]) return mid;
        else if (a[mid] >= a[s]){                  //left half is sorted
            if (key <= a[mid] && key >= a[s]) e = mid - 1;       //element left half me h ..isliye right half ko eliminate kr diya
            else s = mid + 1;                           //element left half me nhi h ...isliye left half ko eliminate kr diya
        }else{                                     //right half is sorted
            if (key >= a[mid] && key <= a[e]) s = mid + 1;       //element right half me h ..isliye left half ko eliminate kr diya
            else e = mid - 1;                           //element right half me nhi h ...isliye right half ko eliminate kr diya

        }
    }
    return -1;
}

int main(){
    int a[] = {3,4,5,6,7,0,1,2};
    int n = sizeof(a) / sizeof(int);
    int key = 4;
    cout << RotatedBsearch(a, n, key);
}