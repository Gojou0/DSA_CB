#include <iostream>
using namespace std;

int main(){
    int a[7] = {1,2,1,3,5,6,4};
    int n = 7;
    if (a[0] > a[1]) return 0;          // edge cases
    if (a[n-1] > a[n-2]) return n - 1;
    int s = 1;
    int e = n - 2;
    while (s <= e){
        int mid = s + (e - s) / 2;
        if (a[mid] > a[mid+1] && a[mid] > a[mid-1]){
            cout << mid << endl; break;
        }
        else if (a[mid] > a[mid-1]) s = mid + 1;            //left half sorted(increasing me h) isliye usko eliminate kr dia
        else e = mid - 1;
    }
}