#include <iostream>
using namespace std;

int BinarySearch(int *a, int n, int target){
    int s = 0;
    int e = n;
    while (s <= e){
        int mid = (s + e) / 2;
        if (target == a[mid]) return mid;
        else if(target <= a[mid]) e = mid - 1;
        else s = mid + 1;
    }
    return -1;
}

int main(){
    int a[] = {1,2,3,4,5,6,7};
    int n = sizeof(a) / sizeof(int);
    int target = 1;
    cout << BinarySearch(a, n, target);
}
